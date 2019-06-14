#include<iostream>
using namespace std;
class bank_account{
public:
    bank_account(int x,int y)
    :pin(x),balanc(y)
    {
    }
    void deposit()
    {
        cout<<"Enter the pin"<<endl;
        cin>>test;
        if(test==pin){
        int dep;
        cout<<"Enter the amount you are going to deposit."<<endl;
        cin>>dep;
        balanc+=dep;
        }
        else{
            cout<<"Pin incorrect !!!"
            return 0;
        }
    }
    void transfer()
    {
         cout<<"Enter the pin"<<endl;
        cin>>test;
        if(test==pin){
        int amt,id;
        cout<<"Enter the amount to transfer";
        cin>>amt;
        cout<<"Enter the account number of the receiptent"<<endl;
        cin>>id;
         }
        else{
            cout<<"Pin incorrect !!!"
            return 0;
        }
    }
    void withdraw()
    {
         cout<<"Enter the pin"<<endl;
        cin>>test;
        if(test==pin){
        int cash;
        cout<<"Enter the amount you want to withdraw"<<endl;
        cin>>cash;
        balanc-=cash;
         }
        else{
            cout<<"Pin incorrect !!!"
            return 0;
        }
    }
    void balance()
    {
         cout<<"Enter the pin"<<endl;
        cin>>test;
        if(test==pin){
        cout<<"The balance in your account is \n"<<balanc;
         }
        else{
            cout<<"Pin incorrect !!!"
            return 0;
        }
    }
private:
    int balanc;
    int pin;
    int test;


};
int main()
{
    bank_account user;
    cout<<"1.DEPOSIT               2.TRANSFER"
    cout<<"3.WITHDRAW              4.BALANCE "
    int cmd;
    cout<<"KINDLY CHOOSE THE OPERATION";
    cin>>cmd;
switch cmd{
   case 1:
    user.deposit();
    break;
   case 2:
    user.transfer();
    break;
   case 3:
    user.withdraw();
    break;
   case 4:
    user.balance;
    break;
   default:
    cout<<"Invalid command"<<endl;
    cout<<"Session terminated";
    return 0;
          }

}
