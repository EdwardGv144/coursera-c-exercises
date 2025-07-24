# Date Struct with Enum (Option 1)

This exercise from the *C for Everyone* course demonstrates how to define and use `structs` and `enums` in C to represent and manipulate calendar dates.

I selected **Option 1** for this task, which involves creating:
- A `month` enum to represent each calendar month
- A `date` struct to store both a month and day
- Helper functions to advance the date and print it in human-readable format

## 🔧 Features

- `printDateAndNextDay()` prints the current date and the date after it.
- `nextDay()` increments the date properly, including wrapping to the next month.
- `maxDate()` checks for month boundaries (fixed to 28 days for February).
- Uses a `switch` statement to map enum values to month names.

## 🧠 Notes

- This implementation assumes non-leap years (February always has 28 days).
- Modular arithmetic ensures months wrap around (e.g., Dec 31 → Jan 1).
- The code already has a couple of examples provided by the course.

## 🛠 How to Compile and Run

```bash
gcc date_struct_enum.c -o date
./date