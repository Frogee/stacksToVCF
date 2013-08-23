CXXFLAGS := -I/usr/include/mysql -I/usr/local/include/mysql++
LDFLAGS := -L/usr/local/lib -L/usr/lib/i386-linux-gnu
LDLIBS := -lmysqlpp -lmysqlclient
EXECUTABLE := stacksToVCF

all: $(EXECUTABLE)

stacksToVCF: stacksToVCF.o stacksDB.o SNP.o
	g++ stacksToVCF.o stacksDB.o SNP.o -o $(EXECUTABLE) $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

stacksToVCF.o: stacksToVCF.cpp
	g++ -c stacksToVCF.cpp

stacksDB.o: stacksDB.cpp
	g++ -c stacksDB.cpp $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

SNP.o: SNP.cpp
	g++ -c SNP.cpp $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)

clean:
	rm -rf *o $(EXECUTABLE)
