OBJECTS = main.o stack.o converter.o
HEADERS = stack.h converter.h
	#(listing all of your object files here, separated by space)
Lab9: $(OBJECTS) 
	g++ $^ -o Lab9
%.o: %.cpp $(HEADERS) 
	g++ -c $< -o $@
clean:
	rm -i *.o Lab9
