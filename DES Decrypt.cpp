Following is the decryption code for DES. 

#include "Encrypt.h"

void xor_oneD(int round) //for Decrypt
{
    int i;
    for(i=0; i<48; i++)
        xor1[i]=expansion[i]^keyi[16-round][i];
}

char* Decrypt(char *Text1)
{
    int i,a1,j,nB,m,iB,k,K,B[8],n,t,d,round;
    char *Text=new char[1000];
    unsigned char ch;
    strcpy(Text,Text1);
    i=strlen(Text);
    int mc=0;
    for(iB=0,nB=0,m=0; m<(strlen(Text)/8); m++) //Repeat for TextLenth/8 times.
    {
        for(iB=0,i=0; i<8; i++,nB++)
        {
            ch=Text[nB];
            n=(int)ch;//(int)Text[nB];
            for(K=7; n>=1; K--)
            {
                B[K]=n%2;  //Converting 8-Bytes to 64-bit Binary Format
                n/=2;
            }
            for(; K>=0; K--) B[K]=0;
            for(K=0; K<8; K++,iB++) total[iB]=B[K]; //Now `total' contains the 64-Bit binary format of 8-Bytes
        }
        IP(); //Performing initial permutation on `total[64]'
        for(i=0; i<64; i++) total[i]=ip[i]; //Store values of ip[64] into total[64]

        for(i=0; i<32; i++) Left[i]=total[i]; //     +--> left[32]
        // total[64]--|
        for(; i<64; i++) Right[i-32]=total[i]; //            +--> right[32]
        for(round=1; round<=16; round++)
        {
            Expansion(); //Performing expansion on `right[32]' to get  `expansion[48]'
            xor_oneD(round);
            Substitution();//Perform substitution on xor1[48] to get sub[32]
            Permutation(); //Performing Permutation on sub[32] to get p[32]
            Xor_two(); //Performing XOR operation on left[32],p[32] to get xor2[32]
            for(i=0; i<32; i++) Left[i]=Right[i]; //Dumping right[32] into left[32]
            for(i=0; i<32; i++) Right[i]=xor2[i]; //Dumping xor2[32] into right[32]
        } //rounds end here
        for(i=0; i<32; i++) temp[i]=Right[i]; // Dumping   -->[ swap32bit ]
        for(; i<64; i++) temp[i]=Left[i-32]; //    left[32],right[32] into temp[64]

        InverseIP(); //Inversing the bits of temp[64] to get inv[8][8]
        /* Obtaining the Cypher-Text into final[1000]*/
        k=128;
        d=0;
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
            {
                d=d+inv[i][j]*k;
                k=k/2;
            }
            final[mc++]=(char)d;
            k=128;
            d=0;
        }
    } //for loop ends here
    final[mc]='\0';
    char *final1=new char[1000];
    for(i=0,j=strlen(Text); i<strlen(Text); i++,j++)
        final1[i]=final[j];
    final1[i]='\0';
    return(final);
}
========================== Main Function =================================
#include "Decrypt.h"

int main()
{
    char *key = new char[8];

    //strcpy(str,"PHOENIX it & ece solutions.");
    cout<<"Enter a Key: ";
    cin >> key;

    FindBitsinKey (key);
    PrintKey();
    KeyGen();
    PrintAllSubKeys();

    char *str=new char[1000];
    char *str1=new char[1000];
    char *str2=new char[1000];

    //strcpy(str,"PHOENIX it & ece solutions.");
    cout<<"Enter a string : ";
    cin >> str;
    str1 = Encrypt(str);
    cout<<"\ni/p Text: "<<str<<endl;
    cout<<"\nCypher  : "<<str1<<endl;
    str2 = Decrypt(str1);
    cout<<"\nPlainText  : "<<str2<<endl;

    getch();

    return 0;
}
