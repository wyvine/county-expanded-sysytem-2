#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Patron {
    char name[100];
    char pass[30];
    char email[50];
    int is_staff;
};
struct books{
    char title[200];
    char pages[100];
    char author[50];
    int is_book;

};
//function prototypes
int save_book(struct books book);
void new_book();
int menu();
void execute_action(int action);
void view_book();
void close();

//function prototypes
int save_patron(struct Patron patron);
void add_patron();
int menu();
void execute_action(int action);
void view_patrons();
void close();
int main()
{
    while(1){
    printf("COUNTY LIBRARY SYSTEM!\n");
    printf("Welcome ivyne wambui!\n");
    execute_action(menu());
    printf("enter any key to continue");
    getch();
    system("cls");

    }

    return 0;
}





int save_patron(struct Patron patron){
    FILE *fp;
    fp = fopen("patrons","ab");
    fwrite(&patron,sizeof(struct Patron),1,fp);
    fclose(fp);
    return 1;
}
int save_book(struct books book){
    FILE *fp;
    fp = fopen("books","ab");
    fwrite(&book,sizeof(struct books),1,fp);
    fclose(fp);
    return 2;
}




void add_patron() {
    struct Patron patron;
    printf("Enter name:");
    getchar();
    gets(patron.name);
    printf("Enter Email:");
    gets(patron.email);
    printf("Initial Password: ");
    gets(patron.pass);
    printf("Enter 1 if staff 0 otherwise: ");
    scanf("%d",&patron.is_staff);
    if(save_patron(patron))
    printf("Patron %s successfully added\n",patron.name);
    else
        printf("unsuccessfully");
 void add_book() {
     struct books book;
     printf("enter title:");
     getchar();
     gets(book.title);
     printf("enter pages:");
     gets(book.pages);
     printf("enter 2 if staff 1 otherwise: ");
     scanf("%d",&books.is_author);
     if(save_book)
     printf("books %s successfully added\n",book.author);
     else
        printf("unsuccessfully");





 }

}

int menu()
{
  int action;
  printf("Select an action:\n");
  printf("1. Add new patron\n");
  printf("2. View Patrons\n");
  printf("3. View Books\n");
  printf("4. Add New Book\n");
  printf("5. exit\n");
  printf("Your Action: ");
  scanf("%d",&action);
  if(action < 1 || action > 5) {
    printf("Invalid action. Try again\n");
  }
  return action;
}

void execute_action(int action) {
    switch(action) {
    case 1:
        add_patron();
        break;
    case 2:
        view_patrons;
        break;
    case 3:
        printf("Here is a list of all books");
        break;
    case 4:
        printf("adding a new Book\n");
        break;
    case 5:
        close();
        break;
    default:
        printf("Invalid action.\n");
    }
}

void view_patrons(){

FILE *fp;
struct Patron patron;
if((fp = fopen("patrons","rb")) == NULL){
printf("unable to open file.\n");
return;
}
printf("%-20s%-20s%-10s\n","NAME","EMAIL","IS STAFF");
while(!feof (fp)){
  fread(&patron,sizeof(struct Patron),1,fp);
  printf("%-20s",patron.name);
  printf("%-20s",patron.email);
  printf("%-10d",patron.is_staff);
}

fclose(fp);
}

void close(){
printf("thank you for using me.\n");
printf("created by ivyne wambui\n");
Sleep(2000);
exit(0);
}


