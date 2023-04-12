all:
      g++ -std=c++17 calculator.cpp -o calculator
      g++ -std=c++17 calulatorTest.cpp -lcppunit -o calculatorTest

test:
      chmod +x hello
      ./calculatorTest

clean:
      $(RM) calculator calculatorTest
