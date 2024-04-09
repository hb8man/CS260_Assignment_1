# CS260_Assignment_1

What the program needs to do(including my own implementations):
  - Display the contents of the bag (for loop w/ cout)
  - Remove a marble (and show color)
  - Add a marble

General structure:
  - Marble class
      - str color (public)
  - Sacc class
      - Collection to store marble obj in: vector<Marble> marbles {red, blue, green, yellow, orange} (public)
      - Methods
          - Add marble
          - Remove marble
          - Show contents of sack

  main() {

  Sack mainSack;
  bool isRunning = true;
  while isRunning = true {
      display menu:
      1. Display contents of sack
      2. Add a marble
          a. Red
          b. Blue
          c. Green
          d. Yellow
          e. Orange
      3. Remove a marble
      4. Exit
  }

  return 0;
  };
