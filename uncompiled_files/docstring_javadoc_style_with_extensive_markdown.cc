/**
 *  A test class. A more elaborate class description.
 */
class Javadoc_Test
{
  public:
 
    /** 
     * An enum.
     * More detailed enum description.
     */
    enum TEnum { 
          TVal1, /**< enum value TVal1. */  
          TVal2, /**< enum value TVal2. */  
          TVal3  /**< enum value TVal3. */  
         } 
       *enumPtr, /**< enum pointer. Details. */
       enumVar;  /**< enum variable. Details. */
       
      /**
       * A constructor.
       * A more elaborate description of the constructor.
       */
      Javadoc_Test();
 
      /**
       * A destructor.
       * A more elaborate description of the destructor.
       */
     ~Javadoc_Test();
    
      /**
       * a normal member taking two arguments and returning an integer value.
       * @param a an integer argument.
       * @param s a constant character pointer.
       * @see Javadoc_Test()
       * @see ~Javadoc_Test()
       * @see testMeToo()
       * @see publicVar()
       * @return The test results
       */
       int testMe(int a,const char *s);
       
      /**
       * A pure virtual member.
       * @see testMe()
       * @param c1 the first argument.
       * @param c2 the second argument.
       */
       virtual void testMeToo(char c1,char c2) = 0;
   
      /** 
       * a public variable.
       * Details.
       */
       int publicVar;
       
      /**
       * a function variable.
       * ### try to emulate some
       * ~deleted text~
       * 
       * `hello`
       * asd
       * 
       * `print("This is syntax specific code block")`
```c++
int i;
float j;
std::string k;
std::cout << i + j << std::endl;
```
       * 
```html
<html>
    <head>
        <title>Test</title>
    </head>
</html>
```
       * Details.
       * a__ | b__ | c__
       * :-|:-:|:-
       * 1|2|3
       * 
       *  ![Tux, the Linux mascot](https://upload.wikimedia.org/wikipedia/commons/a/af/Tux.png)
       * 
       * 
       * - a
       * - b
       * + item
       * + item2
       * - [ ] unchecked
       * - [x] checked
       */
       int (*handler)(int a,int b);
};