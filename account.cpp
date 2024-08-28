#include<iostream>
#include<vector>
using namespace std;

class account{
    private:
    int acc;
    int balance;
    public:
    void input(){
        cout<<"Enter account number: ";
        cin>>acc;
        cout<<"Enter balance: ";
        cin>>balance;
    }
    void display(){
        cout<<"Account Number: "<<acc<<endl;
        cout<<"Balance: "<<balance<<endl;
    }
    void transferByValue(account acc,int amt){
        if(balance>=amt){
            balance-=amt;
            acc.balance+=amt;
        }
        else
        cout<<"Insufficient balance"<<endl;
    }
    void transferByAddress(account *acc,int amt){
        if(balance>=amt){
            balance-=amt;
            acc->balance+=amt;
        }
        else
        cout<<"Insufficient balance"<<endl;
    }
    void transferByReference(account &acc,int amt){
        if(balance>=amt){
            balance-=amt;
            acc.balance+=amt;
        }
        else
            cout<<"Insufficient balance"<<endl;
    }
    int getAccountNumber() const{
        return acc;
    }

};
int main(){
    int n,amount,choice,ip1,ip2;
    int a=-1,b=-1;
    cout<<"Enter the number of accounts: ";
    cin>>n;
    vector<account>accounts(n);
    vector<int>accountNumbers(n);
    for(int i=0;i<n;i++){
        accounts[i].input();
        accountNumbers[i]=accounts[i].getAccountNumber();
    }
    do{
        for(int i=0;i<n;i++){
            accounts[i].display();
        }
        cout<<"enter amt to be transferred: ";
        cin>>amount;
        cout<<"Enter the account number of the sender: ";
        cin>>ip1;
        cout<<"Enter the account number of the receiver: ";
        cin>>ip2;
        for(int i=0;i<n;i++){
            if(accountNumbers[i]==ip1)
            a=i;

            //else(accountNumbers[i]!=ip1);
            //cout<<"invalid acc"<<endl;
        //}
         //for(int i=0;i<n;i++){
            if(accountNumbers[i]==ip2)
            b=i;

           // else(accountNumbers[i]!=ip2);
            //cout<<"invalid acc"<<endl;
        }
        if(a==-1||b==-1){
            cout<<"Invalid account number"<<endl;
            continue;
        }
        cout<<"select 1: transfer by value\n2:transfer by address\n3:transfer by reference\n4:exit"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"transfer by value:...."<<endl;
                accounts[a].transferByValue(accounts[b],amount);
                break;
            case 2:
                cout<<"transfer by address:...."<<endl;
                accounts[a].transferByAddress(&accounts[b],amount);
                break;
            case 3:
                cout<<"transfer by reference...."<<endl;
                accounts[a].transferByReference(accounts[b],amount);
                break;
            case 4: exit(0);
            default:
            cout<<"Invalid choice"<<endl;
        }

    }while(choice!=4);
return 0;
}
