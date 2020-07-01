#!/usr/bin/python3.6
import sys
import argparse

if __name__ == "__main__":

#if len(sys.argv) != 2:
#sys.exit("Not enough args")
	ca_one = str(sys.argv[1])
	ca_two = str(sys.argv[2])

	print ("My command line args are " + ca_one + " and " + ca_two)

	parser = argparse.ArgumentParser()
	parser.add_argument('-p', dest='port', help='RPC port number (if server_addr is IP address)', 
			default=5260, type=int)

	def ad (args):
		print("hellow " + str(args.port) + " morning" )

	args = parser.parse_args()

	ad(args)
	




