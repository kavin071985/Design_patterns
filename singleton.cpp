#include<iostream>

class someClass{
    public: void get(){
        testSingleton ts = testSingleton.getInstance();
        int g =  ts.getX();
        std::cout<<g;
       ts.setX(10);

        testSingleton ts1 = testSingleton.getInstance();
        std::cout<<ts1.getX()<<std::endl;

        ts.setX(50);

        testSingleton ts2 = testSingleton.getInstance();
        std::cout<<ts2.getX()<<std::endl;

        std::cout<<ts1.getX()<<std::endl;
    }
};

 class testSingleton
 {
  private:
     static testSingleton _instance;
     int x;

    testSingleton()
      {
        _instance = null;
        x = 7;
      }

  public:
    static testSingleton getInstance()
    {
       if(null == _instance)
       {
            _instance = new testSingleton();
       }
        return _instance;
    }

    int getX()
    {
       return x;
    }

    void setX(int a)
    {
        x = a;
    }
};

   int main()
   {
        //testSingleton ts = new testSingleton();
        someClass sc = new someClass();
        sc.get();
    }



