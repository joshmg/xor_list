all: 
	g++ -Wall test.cpp xor_list.cpp -o xor_list 

clean:
	rm -f xor_list

