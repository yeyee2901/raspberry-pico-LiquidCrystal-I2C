## Modified Version of I2C LCD Demo
- Modified it so it automatically initialize the I2C bus using the default I2C0 pin.
- Now it supports 16x2 & 20x4 LCD type. Users don't need to worry which type they use.  
- You can use this project as a template too! Just clone it, modify CMakeLists.txt to suit your needs, or you
can just download the file (LiquidCrystal.c & LiquidCrystal.h)
&nbsp;  


- For 16x2 display the row limit is defined as:  
```c
lcd_set_cursor(1, column);
```
  

- For 20x4 display the row limit is defined as:
```c
lcd_set_cursor(3, column);
```


&nbsp;  
#### Note that the position uses ZERO INDEXING, meaning it starts from 0.