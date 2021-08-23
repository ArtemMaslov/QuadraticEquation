# QuadraticEquation
QuadraticEquation is the programm, which solves quadratic equations :)
1. [Usage](#usage)
2. [Input rules](#input-rules)
3. [Compilation](#compilation)
4. [Documentation](#documentation)

### Usage
* Open folder `Release` and run the `QuadraticEquation.exe`.
* The console will be opened.
<p align="center">
    <img src="images/Console.PNG" alt="Console image" width="500"/>
</p>

### Input rules
* The equation must be entered if the form `ax^2 + bx + c = 0`.
* Entered numbers could contain only 6 digit after separator, else the programm prints warning. To increase digits after separator change Epsilon constant.
* The dot `.` and comma `,` could be the decimal separator.
* Multiplication '*' and division '/' symbols are not allowed in the input string. Input `2*x-1=0` is not correct, but `2x-1=0` is correct.
* Each coefficient of quadratic equation can occur only once, otherwise the last one will be use in the calculatios. For example, in the input `2x^2-3x+10x-13=0` member `-3x` will be ignored and this input qual to `2x^2+10x-13=0`.

### Compilation
The project is small so a compilation will not be difficult :) (all source code files are avaliable in the `src` folder).

### Documentation
Open file with documentation `html\index.html`.