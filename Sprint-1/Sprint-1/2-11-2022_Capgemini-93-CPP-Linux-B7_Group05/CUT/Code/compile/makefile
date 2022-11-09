SRCDIR=src
INCLUDEDIR=include
OBJDIR =obj
BINDIR =bin
VALGRIND =tools/valgrind

INCLUDEFLAGS=-I${INCLUDEDIR}
CPPFLAGS= -ansi -c -g -Wall -DDEBUG -std=gnu++11  -I ${INCLUDEDIR}


tester: tester.o conference.o
	g++ -o ${BINDIR}/tester ${OBJDIR}/tester.o ${OBJDIR}/conference.o ${OBJDIR}/rsubmissions.o -lpthread

tester.o:${SRCDIR}/tester.cpp
	g++ -o ${OBJDIR}/tester.o ${CPPFLAGS} ${SRCDIR}/tester.cpp

conference.o:${SRCDIR}/conference.cpp
	g++ -o ${OBJDIR}/conference.o ${CPPFLAGS} ${SRCDIR}/conference.cpp

rsubmissions.o:${SRCDIR}/rsubmissions.cpp
	g++ -o ${OBJDIR}/rsubmissions.o ${CPPFLAGS} ${SRCDIR}/rsubmissions.cpp
	
rpapers.o:${SRCDIR}/rpapers.cpp
	g++ -o ${OBJDIR}/rpapers.o ${CPPFLAGS} ${SRCDIR}/rpapers.cpp

wpapers.o:${SRCDIR}/wpapers.cpp
	g++ -o ${OBJDIR}/wpapers.o ${CPPFLAGS} ${SRCDIR}/wpapers.cpp

articles.o:${SRCDIR}/articles.cpp
	g++ -o ${OBJDIR}/articles.o ${CPPFLAGS} ${SRCDIR}/articles.cpp

blogs.o:${SRCDIR}/blogs.cpp
	g++ -o ${OBJDIR}/blogs.o ${CPPFLAGS} ${SRCDIR}/blogs.cpp

valgrind: tester
	valgrind --leak-check=full --show-reachable=yes ${BINDIR}/tester 2> ${VALGRIND}/valgrind.txt

clean:
	echo "Cleaning files....."
	rm ${BINDIR}/tester ${OBJDIR}/*.o ${VALGRIND}/valgrind.txt
	
