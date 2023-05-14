#include <stdio.h>

int main() {
    int balance = 1000;
    int pin = 1234;
    int choice, amount, new_pin, confirm_pin;

    printf("Welcome to the ATM!\n");

    // Ask user to enter their PIN
    printf("Please enter your PIN: ");
    scanf("%d", &pin);

    // Check if the PIN is correct
    if (pin != 1234) {
        printf("Invalid PIN. Exiting...\n");
        return 0;
    }

    // Display the main menu
    while (1) {
        printf("\nMain Menu:\n");
        printf("1. View Balance\n");
        printf("2. Withdraw Money\n");
        printf("3. Deposit Money\n");
        printf("4. Change PIN\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // View balance
                printf("Your current balance is $%d\n", balance);
                break;
            case 2:
                // Withdraw money
                printf("Enter the amount to withdraw: ");
                scanf("%d", &amount);
                if (amount > balance) {
                    printf("Insufficient funds.\n");
                } else {
                    balance -= amount;
                    printf("Please take your $%d.\n", amount);
                    printf("Your new balance is $%d.\n", balance);
                }
                break;
            case 3:
                // Deposit money
                printf("Enter the amount to deposit: ");
                scanf("%d", &amount);
                balance += amount;
                printf("$%d has been deposited into your account.\n", amount);
                printf("Your new balance is $%d.\n", balance);
                break;
            case 4:
                // Change PIN
                printf("Enter your new PIN: ");
                scanf("%d", &new_pin);
                printf("Confirm your new PIN: ");
                scanf("%d", &confirm_pin);
                if (new_pin != confirm_pin) {
                    printf("PINs do not match.\n");
                } else {
                    pin = new_pin;
                    printf("PIN changed successfully.\n");
                }
                break;
            case 5:
                // Exit program
                printf("Thank you for using the ATM. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}