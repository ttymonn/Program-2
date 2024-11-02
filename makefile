phone: phone.o driver.o
    g++ phone.o driver.o 

review.o: review.cpp
    g++ -c review.cpp

driver.o: driver.cpp
    g++ -c driver.cpp
    
clean:
    rm *.o phone