import openpyxl

# Load the existing Excel file (financesPy.xlsx) from the specified path
path_file = r'C:\Users\veraf\Desktop\Python\financesPy.xlsx'
exclf = openpyxl.load_workbook(path_file)

# Get the active sheet from the loaded workbook
sheet = exclf.active

# Prompt user for their income and expenses
Income = float(input("What is your income? "))
Expense = float(input("How much were your expenses? "))

# Calculate money left (Income - Expense)
Money = Income - Expense

# Write data to cells in the active sheet of the existing workbook
sheet['A1'] = "Income: "
sheet['A2'] = "Expenses: "
sheet['A3'] = "Money left: "
sheet['B1'] = Income
sheet['B2'] = Expense
sheet['B3'] = Money

# Save the changes made to the same existing workbook
exclf.save(path_file)

# Read and print the money left value (from B3, where we stored it)
Money_left = sheet['B3'].value  # Fetch the value from B3 where "Money left" is stored
print(f"Money Left: {Money_left}")
