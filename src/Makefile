TARGET = romannumeralcalculator

$(TARGET): main.o romanNumeralCalculator.a
	gcc $^ -o $@

main.o: main.c
	gcc -c $< -o $@

romanNumeralCalculator.a: romanNumeralCalculator.o
	ar rcs $@ $^

romanNumeralCalcultor.o: romanNumeralCalculator.c romanNumeralCalculator.h
	gcc -c -o $@ $<

clean:
	rm -f *.o *.a $(TARGET)
