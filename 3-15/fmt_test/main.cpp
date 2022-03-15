//
// Created by yi on 2022/3/15.
//
#include <fmt/core.h>
#include <fmt/chrono.h>
#include <iostream>
#include <string>
#include <vector>
#include <fmt/ranges.h>
#include <fmt/os.h>
#include <fmt/color.h>

void FormatAString() {
    std::string s = fmt::format("I'm {0} but {1}.\n", "quiet", "creative");
    fmt::print(s);
}

void PrintChronoDurations() {
    using namespace std::literals::chrono_literals;
    fmt::print("Default format: {} {}.\n", 42s, 100ms);
    fmt::print("strftime-like format: {:%H:%M:%S}\n", 3h + 15min + 30s);
}

void PrintAContainer() {
    std::vector<int> v = {1, 2, 3};
    fmt::print("{}\n", v);
}

void WriteAFileFromASingleThread() {
    auto out = fmt::output_file("/home/yi/Projects/PracticeBar/PracticeBar/3-15/fmt_test/fmt_output.txt");
    out.print("Hello from {}!\n", "fmt_test");
}

void PrintWithColorsAndTextStyle() {
    fmt::print(fg(fmt::color::alice_blue) | fmt::emphasis::bold, "Hello, {}!\n", "Yi");
}

int main(int argc, char* argv[]) {
    std::cout << "Testing fmt..." << std::endl;
    fmt::print("Testing fmt fl...\n");

    FormatAString();

    PrintChronoDurations();

    PrintAContainer();

    // WriteAFileFromASingleThread();

    PrintWithColorsAndTextStyle();  // text color seems not working...
}
