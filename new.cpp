#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Doctors_db{

    char doc_name[100];
    char doc_id[100];
    int  doc_age;
    char doc_category[50];
    char doc_gender[10];
    char doc_institute[100];
    char doc_level[20];
    float doc_salary;
    char doc_blood_grp[10];
    char doc_email[100];

};
int main()
{
    char stf[50];
    char stp[50];
    printf("User name........::->");
    gets(stf);
    printf("User password.....::->");
    gets(stp);
    if((strcmp(stf,"Uap cse")==0) && (strcmp(stp,"104")==0))
    {
    printf("*********************************         WELCOME     ***************************************\n");


    Doctors_db s[50];
    FILE *fr;
    fr=fopen("doc_statement.txt","r");
    int counter=0;
    char str[100];
    while(fgets(str,100,fr)!=NULL)
    {
    counter++;
    }
    printf("                                 Number of the doctors= %d\n",counter);
    rewind(fr);
    char newline;
    for(int i=0;i<50;i++)
    {
    fscanf(fr,"%[^:]:%[^:]:%d:%[^:]:%[^:]:%[^:]:%[^:]:%f:%[^:]:%s",s[i].doc_name,s[i].doc_id,&s[i].doc_age,s[i].doc_category,s[i].doc_gender,s[i].doc_institute,s[i].doc_level,&s[i].doc_salary,s[i].doc_blood_grp,s[i].doc_email);
    }
    int n;
    while(1)
    {
    printf("\nPlease Enter Your Choice::->\n\n");
    printf("\nPress <1> to see Youngest Doctor:->\n");
    printf("\nPress <2> to see Doctor Highest salary with Age:->\n");
    printf("\nPress <3> to see Oldest Doctor with level:->\n");
    printf("\nPress <4> to see Doctors Minimum salary :->\n");
    printf("\nPress <5> to see MBBS Doctor with institute:->\n");
    printf("\nPress <6> to see Doctors salary with level:->\n");
    printf("\nPress <7> to see Category with blood group:->\n");
    printf("\nPress <8> to see Doctors name and institute :->\n");
    printf("\nPress <9> to see Doctor with institute:->\n");
    printf("\nPress <10> to see Doctors category with level:-> \n");
    printf("\nPress <0> to exit:-> \n");
    scanf("%d",&n);
    if(n==1)
    {
    printf("Press (0) to see youngest doctor:->\n");
    printf("Press (1) to see youngest female doctor:->\n");
    printf("Press (2) to see youngest male doctor:->\n");
    printf("Press (3) to see doctors between age 29-40:->\n");
    printf("Press (4) to exit\n");
    int flag;
    scanf("%d",&flag);
    if(flag==1)
    {
    int min_age=s[0].doc_age;
    int min_index=0;
    for(int i=0;i<50;i++)
    {
    if(strcmp(s[i].doc_gender,"Female")==0)
    {
    min_age=s[i].doc_age;
    min_index=i;
    }
    }
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_age<min_age) && (strcmp(s[i].doc_gender,"Female")==0))
    {
    min_age=s[i].doc_age;
    min_index=i;

    }
    }
    printf("Doctor name->");
    puts(s[min_index].doc_name);
    printf("Doctor gender->");
    puts(s[min_index].doc_gender);
    printf("Docttor ID->");
    puts(s[min_index].doc_id);
    printf("Doctor age= %d\n",s[min_index].doc_age);

    }

    if(flag==2)
        {
        int min_age=s[0].doc_age;
        int min_index=0;
        for(int i=0;i<50;i++)
       {
        if(strcmp(s[i].doc_gender,"Male")==0)
        {
        min_age=s[i].doc_age;
        min_index=i;
        }
        }
        for(int i=0;i<50;i++)
        {
        if((s[i].doc_age<min_age) && (strcmp(s[i].doc_gender,"Male")==0))
        {
        min_age=s[i].doc_age;
        min_index=i;
        }
        }
        printf("Doctor name->");
        puts(s[min_index].doc_name);
        printf("Doctor gender->");
        puts(s[min_index].doc_gender);
        printf("Docttor ID->");
        puts(s[min_index].doc_id);
        printf("Doctor age= %d\n",s[min_index].doc_age);

        }


        if(flag==3)
        {
        for(int i=0;i<50;i++)
        {
        if((s[i].doc_age>=29) && (s[i].doc_age<=39))
        {
        printf("Doctor name->");
        puts(s[i].doc_name);
        printf("Doctor age =%d\n",s[i].doc_age);
        printf("Doctor category->");
        puts(s[i].doc_category);
        printf("Doctor level->");
        puts(s[i].doc_level);

        }
        }
        }
        if(flag==0)
        {
        int min_age=s[0].doc_age;
        int min_index=0;
        for(int i=0;i<50;i++)
        {
        if(s[i].doc_age<min_age)
        {
        min_age=s[i].doc_age;
        min_index=i;
        break;
        }
        }
        printf("Doctor name->");
        puts(s[min_index].doc_name);
        printf("Doctor ID->");
        puts(s[min_index].doc_id);
        }
        if(flag==4)
        {
        exit(0);
        }
        }

    else if(n==2)
    {
    printf("Press (1) to see doctor highest salary:->\n");
    printf("Press (2) to see doctor highest salary within 29-50:->\n");
    printf("Press (0) to exit\n");
    int flag;
    scanf("%d",&flag);
    if(flag==1)
    {
    int high_salary=s[0].doc_salary;
    int max_salary=0;
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_salary>high_salary))
    {

    high_salary=s[i].doc_salary;
    max_salary=i;
    }

    }
    printf("Doctor Name:->");
    puts(s[max_salary].doc_name);
    printf("Doctor ID:->");
    puts(s[max_salary].doc_id);
    printf("Doctor Level:->");
    puts(s[max_salary].doc_level);
    printf("Doctor Category:->");
    puts(s[max_salary].doc_category);

    }

    if(flag==2)
    {
    int high_salary=s[0].doc_salary;
    int max_salary=0;
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_salary>high_salary)&& (s[i].doc_age>=29)&&(s[i].doc_age<=50))
    {

    high_salary=s[i].doc_salary;
    max_salary=i;
    }

    }
    printf("Doctor Name:->");
    puts(s[max_salary].doc_name);
    printf("Doctor Level:->");
    puts(s[max_salary].doc_level);
    printf("Doctor Category:->\n");
    puts(s[max_salary].doc_category);

    }

    if(flag==0)
    {
    exit(0);

    }

    }

    else if(n==3)
    {
    printf("Press (1) to see oldest doctor:->\n");
    printf("Press (2) to see oldest female doctor:->\n");
    printf("Press (3) to see oldest male doctor:->\n");
    printf("Press (4) to see oldest doctors within 40-48:->\n");
    printf("Press (0) for exit\n");
    int flag;
    scanf("%d",&flag);
    if(flag==2)
    {
    int max_age=s[0].doc_age;
    int max_index=0;
    for(int i=0;i<50;i++)
    {
    if(strcmp(s[i].doc_gender,"Female")==0)
    {
    max_age=s[i].doc_age;
    max_index=i;

    }
    }
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_age>max_age) && (strcmp(s[i].doc_gender,"Female")==0))
    {
    max_age=s[i].doc_age;
    max_index=i;

    }
    }
    printf("Doctor name->");
    puts(s[max_index].doc_name);
    printf("Doctor gender->");
    puts(s[max_index].doc_gender);
    printf("Docttor ID->");
    puts(s[max_index].doc_id);
    printf("Doctor age= %d\n",s[max_index].doc_age);

    }


        if(flag==3)
        {
        int max_age=s[0].doc_age;
        int max_index=0;
        for(int i=0;i<50;i++)
       {
        if(strcmp(s[i].doc_gender,"Male")==0)
        {
        max_age=s[i].doc_age;
        max_index=i;

        }
        }
        for(int i=0;i<50;i++)
        {
        if((s[i].doc_age>max_age) && (strcmp(s[i].doc_gender,"Male")==0))
        {
        max_age=s[i].doc_age;
        max_index=i;
        }
        }
        printf("Doctor name->");
        puts(s[max_index].doc_name);
        printf("Doctor gender->");
        puts(s[max_index].doc_gender);
        printf("Docttor ID->");
        puts(s[max_index].doc_id);
        printf("Doctor age= %d\n",s[max_index].doc_age);
        }


        if(flag==4)
        {
        for(int i=0;i<50;i++)
        {
        if((s[i].doc_age>=40) && (s[i].doc_age<=48))
        {
        puts(s[i].doc_name);
        printf("Doctor age= %d\n",s[i].doc_age);
        printf("Doctor category:->");
        puts(s[i].doc_category);
        printf("Doctor level:->");
        puts(s[i].doc_level);
        }
        }
        }

        if(flag==1)
        {
        int max_age=s[0].doc_age;
        int max_index=0;
        for(int i=0;i<50;i++)
        {
        if(s[i].doc_age>max_age)
        {
        max_age=s[i].doc_age;
        max_index=i;

        }
        }
        printf("Doctor name:->");
        puts(s[max_index].doc_name);
        printf("Doctor ID:->");
        puts(s[max_index].doc_id);

        }

        if(flag==0)
        {
        exit(0);
        }
    }


    else if(n==4)
    {
    printf("Press (1) to see doctor minimum salary:->\n");
    printf("Press (2) to see doctor minimum salary within 29-50:->\n");
    printf("Press (0) for exit\n");
    int flag;
    scanf("%d",&flag);
    if(flag==1)
    {
    int min_salary=s[0].doc_salary;
    int min_index=0;
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_salary<min_salary))
    {

    min_salary=s[i].doc_salary;
    min_index=i;
    }

    }
    printf("Doctor Nmae:-");
    puts(s[min_index].doc_name);
    printf("Doctor ID:->");
    puts(s[min_index].doc_id);
    printf("Doctor Level:-\n");
    puts(s[min_index].doc_level);
    printf("Doctor Category:-\n");
    puts(s[min_index].doc_category);
    }

    if(flag==2)
    {
    int min_salary=s[0].doc_salary;
    int min_index=0;
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_salary>min_salary)&& (s[i].doc_age>=29)&&(s[i].doc_age<=50))
    {

    min_salary=s[i].doc_salary;
    min_index=i;
    }

    }
    printf("Doctor Nmae:-");
    puts(s[min_index].doc_name);
    printf("Doctor Level:-");
    puts(s[min_index].doc_level);
    printf("Doctor Category:-");
    puts(s[min_index].doc_category);

    }
    if(flag==0)
    {
    exit(0);

    }
    }

    else if(n==5)
    {
    int flag;
    printf("Press (1) to see MBBS Doctors in DMC institute:-\n");
    printf("Press (2) to see MBBS Doctors in SOMC institute:-\n");
    printf("Press (0) for exit\n");
    scanf("%d",&flag);
    if(flag==1)
    {
    for(int i=0;i<50;i++)
    {
    if((strcmp(s[i].doc_level,"MBBS")==0) && (strcmp(s[i].doc_institute,"DMC")==0))
    {
    puts(s[i].doc_name);
    puts(s[i].doc_id);

    }
    }
    }
     if(flag==2)
    {
    for(int i=0;i<50;i++)
    {
    if((strcmp(s[i].doc_level,"MBBS")==0) && (strcmp(s[i].doc_institute,"SOMC")==0))
    {
    printf("Doctor name:->");
    puts(s[i].doc_name);
    printf("Doctor name:->");
    puts(s[i].doc_id);
    }
    }
    }
    if(flag==0)
    {
    exit(0);

    }
    }

    else if(n==6)
    {
    printf("Press (1) to see minimum salary with MBBS level\n");
    printf("Press (2) to see maximum salary with PhD level\n");
    printf("Press (0) for exit\n");
    int flag;
    scanf("%d",&flag);
    if(flag==1)
    {
    int min_salary=s[0].doc_salary;
    int min_index=0;
    {
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_salary<min_salary) && (strcmp(s[i].doc_level,"MBBS")==0))
    {
    min_salary=s[i].doc_salary;
    min_index=i;
    }
    }
    }
    printf("Doctor name:->");
    puts(s[min_index].doc_name);
    printf("Doctor ID:->");
    puts(s[min_index].doc_id);

    }

    if(flag==2)
    {
    int max_salary=s[0].doc_salary;
    int max_index=0;
    {
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_salary>max_salary) && (strcmp(s[i].doc_level,"PhD")==0))
    {
    max_salary=s[i].doc_salary;
    max_index=i;
    }
    }
    printf("Doctor name:->");
    puts(s[max_index].doc_name);
    printf("Doctor ID:->");
    puts(s[max_index].doc_id);
    printf("%f",s[max_index].doc_salary);

    }
    }

    if(flag==0)
    {
    exit(0);

    }
    }
    else if(n==7)
    {
    for(int i=0;i<50;i++)
    {
    if((strcmp(s[i].doc_category,"DENTIST")==0) && (strcmp(s[i].doc_blood_grp,"B+")==0))
    {
    puts(s[i].doc_name);
    puts(s[i].doc_id);

    }
    }

    }
    else if(n==8)
    {
    for(int i=0;i<50;i++)
    {
    printf("Doctor name:->");
    puts(s[i].doc_name);
    printf("Doctor ID:->");
    puts(s[i].doc_id);
    printf("Doctor gender:->");
    puts(s[i].doc_gender);
    printf("Doctor Institute:->");
    puts(s[i].doc_institute);

    }
    }

    else if(n==9)
    {
    for(int i=0;i<50;i++)
    {
    if((s[i].doc_id)&& (s[i].doc_email))
    {
    printf("Doctor name:->");
    puts(s[i].doc_name);
    printf("Doctor E-mail:->");
    puts(s[i].doc_email);
    }
    }
    }
    else if(n==10)
    {
     printf("Press (1) to see  Neurology doctor with MBBS level:- \n");
     printf("Press (2) to see  Plastic Surgeon doctor with MBBS level:- \n");

    int flag;
    scanf("%d",&flag);
    if(flag==1)
    {
    for(int i=0;i<50;i++)
    {
    if((strcmp(s[i].doc_category,"NEUROLOGY")==0) && (strcmp(s[i].doc_level,"MBBS")==0))
    {
    printf("Doctor name:->");
    puts(s[i].doc_name);
    printf("Doctor ID:->");
    puts(s[i].doc_id);
    }
    }

    if(flag==2)
    {
    for(int i=0;i<50;i++)
    {
    if((strcmp(s[i].doc_category,"Plastic Surgeon")==0)  && (strcmp(s[i].doc_level,"MBBS")==0))
    {
    printf("Doctor name:->");
    puts(s[i].doc_name);
    printf("Doctor ID:->");
    puts(s[i].doc_id);

    }
    }
    }
    }
    }


    else if(n==0)
    {
    exit(0);
    }

    }
    fclose(fr);

    }
    else
    {
    printf("Try Again");
    }

}


