#include <iostream>
#include<string>
#include <limits>    // برای استفاده از محدودیت‌های عددی

// تابعی برای اعتبارسنجی پیش شماره کارت
bool isValidPrefix(const std::string& prefix) {
    // پیش شماره‌های معتبر کارت بانکی
    const std::string validPrefixes[] = { "6037", "5892", "6274", "6273", "5022", "6393" };
    // بررسی هر پیش شماره معتبر
    for (const auto& validPrefix : validPrefixes) {
        // اگر پیش شماره معتبر باشد، true برگردان
        if (prefix == validPrefix) {
            return true;
        }
    }
    // اگر پیش شماره معتبر نباشد، false برگردان
    return false;
}

int main() {
    int cardNumber[16];  // آرایه‌ای برای ذخیره شماره کارت
    std::string currentNumber;  // رشته‌ای برای نمایش شماره کارت تا لحظه جاری
    bool isValid = true;  // متغیری برای بررسی اعتبار کارت

    std::cout << "Please enter your 16-digit bank card number one digit at a time:" << std::endl;  // پیام اولیه برای دریافت شماره کارت

    for (int i = 0; i < 16; ++i) {
        int digit;
        std::cout << "Digit " << i + 1 << ": ";  // درخواست برای وارد کردن رقم
        // بررسی ورودی عددی و معتبر بودن آن
        while (!(std::cin >> digit) || digit < 0 || digit > 9) {
            std::cout << "Error: Please enter a valid digit between 0 and 9." << std::endl;  // پیام خطا در صورت ورودی نامعتبر
            std::cin.clear();  // پاک کردن وضعیت خطا
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // پاک کردن بافر ورودی
            std::cout << "Digit " << i + 1 << ": ";  // درخواست مجدد برای وارد کردن رقم
        }

        cardNumber[i] = digit;  // ذخیره رقم در آرایه
        currentNumber += std::to_string(digit);  // اضافه کردن رقم به رشته‌ی نمایش

        std::cout << "Card number so far: " << currentNumber << std::endl;  // نمایش شماره کارت تا لحظه جاری

        // اعتبار سنجی پیش شماره بعد از وارد کردن ۴ رقم اول
        if (i == 3) {
            if (isValidPrefix(currentNumber)) {
                std::cout << "Card prefix is valid." << std::endl;  // پیش شماره معتبر است
            }
            else {
                std::cout << "Card prefix is invalid." << std::endl;  // پیش شماره نامعتبر است
                isValid = false;
            }
        }
    }

    // نمایش شماره کارت ۴ رقم ۴ رقم
    if (isValid) {
        std::cout << "Your card number is: ";
        for (int i = 0; i < 16; i++) {
            std::cout << cardNumber[i];  // نمایش هر رقم
            if ((i + 1) % 4 == 0 && i != 15) {
                std::cout << " ";  // افزودن فاصله بعد از هر ۴ رقم
            }
        }
        std::cout << std::endl;
    }
    else {
        std::cout << "Your card number is invalid." << std::endl;  // پیام نامعتبر بودن شماره کارت
    }

    return 0;
}
