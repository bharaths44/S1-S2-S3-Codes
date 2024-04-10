#include<iostream>
#include<string>
using namespace std;
class patient {
    public :
        int patientID;
        string Pname;
        void getpatientinfo(int i);
        void putpatientinfo(int i);
        void makeappointment();
        void diagnosis();
        void billing();
        void printbill(int i);   
        
    private :
        string address,gender,phone,bloodgrp,d_name,app_date,Diagnosisinfo,Medicineinfo;
        int doctorfee,medicine_charge,total;
};

void patient::getpatientinfo(int i)
{
    patientID=i;
    cout<<"Enter the name :";
    cin>>Pname;
    cout<<"Enter the address :";
    cin>>address;
    cout<<"Enter the gender :";
    cin>>gender;
    cout<<"Enter the phone number :";
    cin>>phone;
    cout<<"Enter the blood group :";
    cin>>bloodgrp;
}

void patient::putpatientinfo(int i)
{
    patientID=i;
    cout<<"Patient ID :"<<patientID<<endl;
    cout<<"Name :"<<Pname<<endl;
    cout<<"Address :"<<address<<endl;
    cout<<"Gender :"<<gender<<endl;
    cout<<"Phone :"<<phone<<endl;
    cout<<"Blood group :"<<bloodgrp<<endl;
}

void patient::makeappointment()
{
    cout<<"Enter the doctor name :";
    cin>>d_name;
    cout<<"Enter the appointment date :";
    cin>>app_date;
}

void patient::diagnosis()
{
    cout<<"Enter diagnosis information :";
    cin>>Diagnosisinfo;
    cout<<"Enter medicine info :";
    cin>>Medicineinfo;
}

void patient::billing()
{
    cout<<"Enter the doctor fee :";
    cin>>doctorfee;
    cout<<"Enter the medicine charge :";
    cin>>medicine_charge;
    total=doctorfee+medicine_charge;
}

void patient::printbill(int i)
{
    patientID=i;
    cout<<"\n\n************** BILL **************"<<endl;
    cout<<"**********************************"<<endl;
    cout<<"\tPatient ID :"<<i<<endl;
    cout<<"\tName :"<<Pname<<endl;
    cout<<"\tGender :"<<gender<<endl;
    cout<<"\tDoctor Name :"<<d_name<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"\tDoctor fee :"<<doctorfee<<endl;
    cout<<"\tMedicine charge :"<<medicine_charge<<endl;
    cout<<"\tTotal :"<<total<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"***********************************\n\n"<<endl;
    

}

int main()
{
    int ch,i;
    patient p[100];
    while(1)
   {
        cout<<"************ Sunrise Hospital ************"<<endl;
        cout<<"\t1. Enter patient details\n\t2. Print patient details\n\t3. Make appointment\n\t4. Diagnosis info\n\t5. Billing\n\t6. View Bill\n\t7. Exit\n";
        cout<<"******************************************"<<endl;
        cout<<"Enter the choice :";
        cin>>ch;
        if(ch==7)
        {
            cout<<"Thank you"<<endl;
            break;
          }
        cout<<"Enter the patient ID :";
        cin>>i;
        switch(ch)
        {
            case 1:
                p[i].getpatientinfo(i);
                break;
            case 2:
                p[i].putpatientinfo(i);
                break;
            case 3:
                p[i].makeappointment();
                break;
            case 4:
                p[i].diagnosis();
                break;
            case 5:
                p[i].billing();
                break;
            case 6:
                p[i].printbill(i);
                break;
            default :
                cout<<"Wrong option"<<endl;
                break; 
           }
    }  
 }
