#include<iostream>
#include <boost/format.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <fcntl.h> // for open
#include <unistd.h> // for close
#include <arpa/inet.h>
#include <system_error>

#include <regex>

using namespace std;
/**************************************************************************/
/* Constants used by this program                                         */
/**************************************************************************/
#define SERVER_PATH     "/var/tmp/spdk.sock"
#define BUFFER_LENGTH    250
#define FALSE              0

/* Pass in 1 parameter which is either the */
/* path name of the server as a UNICODE    */
/* string, or set the server path in the   */
/* #define SERVER_PATH which is a CCSID    */
/* 500 string.                             */

int client()
{
    /***********************************************************************/
    /* Variable and structure definitions.                                 */
    /***********************************************************************/
    int    sd=-1, rc, bytesReceived;
    char   buffer[BUFFER_LENGTH];
    struct sockaddr_un serveraddr;

    /***********************************************************************/
    /* A do/while(FALSE) loop is used to make error cleanup easier.  The   */
    /* close() of the socket descriptor is only done once at the very end  */
    /* of the program.                                                     */
    /***********************************************************************/
    do
    {
        /********************************************************************/
        /* The socket() function returns a socket descriptor, which represents   */
        /* an endpoint.  The statement also identifies that the UNIX  */
        /* address family with the stream transport (SOCK_STREAM) will be   */
        /* used for this socket.                                            */
        /********************************************************************/
        sd = socket(AF_UNIX, SOCK_STREAM, 0);
        if (sd < 0)
        {
            perror("socket() failed");
            break;
        }

        /********************************************************************/
        /* If an argument was passed in, use this as the server, otherwise  */
        /* use the #define that is located at the top of this program.      */
        /********************************************************************/
        memset(&serveraddr, 0, sizeof(serveraddr));
        serveraddr.sun_family = AF_UNIX;
        strcpy(serveraddr.sun_path, SERVER_PATH);

        /********************************************************************/
        /* Use the connect() function to establish a connection to the      */
        /* server.                                                          */
        /********************************************************************/

        rc = connect(sd, (struct sockaddr *)&serveraddr, SUN_LEN(&serveraddr));
        if (rc < 0)
        {
            perror("connect() failed");
        //    break;
            std::string warn(str(format("Failed to connect to server @ %1%") % SERVER_PATH)); 
            throw std::system_error(errno, std::generic_category(), warn.c_str());
        }

        /********************************************************************/
        /* Send 250 bytes of a's to the server                              */
        /********************************************************************/
        memset(buffer, 0, sizeof(buffer));


        boost::property_tree::ptree pt;
        std::ostringstream ss;
#if 0
        pt.add("jsonrpc", "2.0");
        pt.add("id", 1);
        pt.add( "method", "bdev_set_options");
        boost::property_tree::ptree params;

        params.add( "bdev-io-pool-size", 65536);
        params.add( "bdev-io-cache_size", 256);
        pt.add_child("params", params);
#endif

        boost::property_tree::ptree params;
        pt.add("jsonrpc", "2.0");
        pt.add( "method", "bdev_malloc_create");
        pt.add("id", 1);
        params.add("num_blocks", 65);
        params.add("block_size", 512);
        params.add("name", "MallocVVS");
       // params.add("uuid", "2b6601ba-eada-44fb-9a83-a20eb9eb9e90");
        pt.add_child("params", params);
        boost::property_tree::json_parser::write_json(ss, pt);

        cout << ss.str() << endl;
        std::string s = ss.str();
        cout << s << endl;


        std::regex reg("\\\"([0-9]+\\.{0,1}[0-9]*)\\\"");
        std::string result = std::regex_replace(ss.str(), reg, "$1");
        uint32_t t_len =  result.length();// htonl(ss.str().length());
        cout << "result " << result << endl;
        cout << " buffer lenf " << t_len  << endl;
        rc = send(sd, result.c_str(), t_len, 0);

        if (rc < 0)
        {
            perror("send() failed");
            break;
        }

        /********************************************************************/
        /* In this example we know that the server is going to respond with */
        /* the same 250 bytes that we just sent.  Since we know that 250    */
        /* bytes are going to be sent back to us, we can use the          */
        /* SO_RCVLOWAT socket option and then issue a single recv() and     */
        /* retrieve all of the data.                                        */
        /*                                                                  */
        /* The use of SO_RCVLOWAT is already illustrated in the server      */
        /* side of this example, so we will do something different here.    */
        /* The 250 bytes of the data may arrive in separate packets,        */
        /* therefore we will issue recv() over and over again until all     */
        /* 250 bytes have arrived.                                          */
        /********************************************************************/
        bytesReceived = 0;
        while (bytesReceived < BUFFER_LENGTH)
        {
            rc = recv(sd, & buffer[bytesReceived],
                    BUFFER_LENGTH - bytesReceived, 0);
            if (rc < 0)
            {
                perror("recv() failed");
                break;
            }
            else if (rc == 0)
            {
                printf("The server closed the connection\n");
                break;
            }

            /*****************************************************************/
            /* Increment the number of bytes that have been received so far  */
            /*****************************************************************/
            bytesReceived += rc;
        }

    } while (FALSE);

            cout << buffer << endl;
            /***********************************************************************/
            /* Close down any open socket descriptors                              */
            /***********************************************************************/
            if (sd != -1)
                close(sd);

}
int main(int argc, char *argv[])
{
    try
    {
        client();
    }
    catch (std::system_error& ex)
    {
        //    std::cout << "Error: " << error.code() << " - " << error.what() << '\n';
        std::cout << ex.code() << '\n';
        std::cout << ex.code().message() << '\n';
        std::cout << ex.what() << '\n';
    }
    return 0;
}
