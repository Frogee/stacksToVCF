CXXFLAGS := -I/usr/include/mysql -I/usr/local/include/mysql++
LDFLAGS := -L/usr/local/lib -L/usr/lib/i386-linux-gnu
LDLIBS := -lmysqlpp -lmysqlclient
EXECUTABLE := stacksToVCF

all: $(EXECUTABLE)

stacksToVCF: stacksToVCF.o stacksDB.o
	g++ stacksToVCF.o stacksDB.o $(CXXFLAGS) $(LDFLAGS) $(LDLIBS) -o $(EXECUTABLE)

stacksToVCF.o: stacksToVCF.cpp
	g++ -c stacksToVCF.cpp

stacksDB.o: stacksDB.cpp
	g++ -c stacksDB.cpp $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf *o $(EXECUTABLE)
