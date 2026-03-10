def check_password_strength(password):
    length = len(password)
    has_upper = any(c.isupper() for c in password)
    has_lower = any(c.islower() for c in password)
    has_digit = any(c.isdigit() for c in password)
    has_special = any(c in "!@#$%^&*()_+-=[]{}|;':\",./<>?" for c in password)

    score = 0
    feedback = []

    
    if length >= 8:
        score += 1
    else:
        feedback.append(" Password should be at least 8 characters long")

    if length >= 12:
        score += 1
    elif length >= 8:
        feedback.append(" Consider using 12+ characters for a stronger password")

  
    if has_upper:
        score += 1
    else:
        feedback.append(" Add uppercase letters (A-Z)")

    if has_lower:
        score += 1
    else:
        feedback.append(" Add lowercase letters (a-z)")

    if has_digit:
        score += 1
    else:
        feedback.append(" Add numbers (0-9)")

    if has_special:
        score += 1
    else:
        feedback.append(" Add special characters (!@#$%^&*...)")

    if score <= 2:
        strength = "Very Weak "
    elif score == 3:
        strength = "Weak "
    elif score == 4:
        strength = "Fair "
    elif score == 5:
        strength = "Strong "
    else:
        strength = "Very Strong "

    return strength, score, feedback


def main():
    print("=" * 40)
    print("      PASSWORD STRENGTH CHECKER")
    print("=" * 40)

    while True:
        password = input("\nEnter a password to check (or 'quit' to exit): ")

        if password.lower() == 'quit':
            print("Goodbye!")
            break

        if not password:
            print("Please enter a password.")
            continue

        strength, score, feedback = check_password_strength(password)

        print(f"\n Strength: {strength}")
        print(f" Score: {score}/6")

        if feedback:
            print("\n Suggestions:")
            for tip in feedback:
                print(f"   {tip}")
        else:
            print("\n Excellent! Your password meets all criteria.")

        print("-" * 40)


if _name_ == "_main_":
    main()

