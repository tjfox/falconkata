testromannumeralcalculator: checkRomanNumeralCalculator.o ../src/romanNumeralCalculator.a
	gcc $^ -lcheck -lpthread -lm -lrt -o $@

checkRomanNumeralCalculator.o: checkRomanNumeralCalculator.c
	gcc -c $< -o $@

clean:
	rm *.o
	rm testromannumeralcalculator
