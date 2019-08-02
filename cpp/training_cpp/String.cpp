#include<cstring>

using namespace std;

class List;

class String {
    char *buf;
    int size;

    public:
      String() {
          size = 0;
          buf = new char[1];
          *buf ='\0';
      }
      String(const char *p)
      {
          size = strlen(p);
          buf = new char[size + 1];
          strcpy(buf, p);
          *(buf + size) = '\0';
      }

      String(String &t)
      {
          size = t.length();
          buf = new char[size + 1];
          strcpy(buf, t.buf);
          *(buf + size) = '\0';

      }

      int length() 
      {
          return size;
      }

      void show()
      {
          cout << buf << endl;
      }

      String& operator=(String& t)
      {
          delete[] buf;
          size = t.size;
          buf = new char [size + 1];
          strcpy(buf , t.buf);
          buf[size + 1 ] = '\0';
          return *this;
      }


      //String s1 = s2 + s3;
      //move copy constructor
      String(String&& t)
      {
          cout << "move copy construcot " << endl;
          size = t.size;
          buf = t.buf; 
          t.buf = nullptr;
          //delete &t
      }


      //move assigment operator
      String& operator=(String&& t)
      {

          cout << " move assingment const " << endl;
        size = t.size;
        delete[] buf;
        buf = t.buf;
        t.buf = nullptr;
      }

      List& split(char *str, char d)
      {
          
          return 
      }

      String& operator+(const String& t)
      {
          String *temp = new String();
          delete[] temp->buf;
          temp->size = size + t.size;
          temp->buf = new char[temp->size + 1];
          strcpy(temp->buf, buf)
          strcat(temp->buf, t.buf)
          temp->buf[temp->size + 1] = '\0';
          return *temp;
      }

      ~String() 
      {
          delete[] buf;
      }
};
