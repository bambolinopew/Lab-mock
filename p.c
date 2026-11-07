#include<stdio.h>
#include<cs50.h>
int main(void){
    int prices[10];
    int count=0;
    int choice;
    do
    {
        printf("       Shopping Cart Manager\n");
        printf("1. Add product prices\n");
        printf("2. Display All prices\n");
        printf("3. Calculate Total\n");
        printf("4. Search for a price\n");
        printf("5. Remove a product\n");
        printf("6. Exit\n");
        choice=get_int("Enter your choice:");

        if(choice==1)
        {
            int n=get_int("How many prices do you want to add?");
            if(n<=0 || count+n>10)
            {
                printf("Invalid number! Maximum capacity is 10.\n");
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                    prices[count]=get_int("Enter product price:");
                    count++;
                }
                printf("Prices added successfully\n");
            }
        }
        else if(choice==2)
        {
            if(count==0)
            {
                printf("Shopping cart is empty\n");
            }
            else
            {
                printf("Product prices:\n");
                for(int i=0;i<count;i++)
                {
                    printf("%d. %d Tk\n",i+1,prices[i]);
                }
            }
        }
        else if(choice==3)
        {
            int total=0;
            for(int i=0;i<count;i++)
            {
                total=total+prices[i];
            }
            printf("Total price=%d Tk\n",total);
        }
        else if(choice==4)
        {
            int search_price;
            int found=0;
            search_price=get_int("Enter the price to search:");
            for(int i=0;i<count;i++)
            {
                if(prices[i]==search_price)
                {
                    printf("Price found at position %d\n",i+1);
                    found=1;
                    break;
                }
            }
            if(found==0)
            {
                printf("Price not found!\n");
            }
        }
        else if(choice==5)
        {
            int position;
            if(count==0)
            {
                printf("Shopping cart is empty!\n");
            }
            else
            {
                position=get_int("Enter product position to remove:");
                if(position<1 || position>count)
                {
                    printf("Invalid position!\n");
                }
                else
                {
                    int *ptr=&prices[position-1];
                    printf("Removed price: %d Tk\n",*ptr);
                    for(int i=position-1;i<count-1;i++)
                    {
                        prices[i]=prices[i+1];
                    }
                    count--;
                    printf("Product removed successfully!\n");
                }
            }
        }
        else if(choice==6)
        {
            printf("Thank you for using Shopping Cart Manager!\n");
        }
        else
        {
            printf("Invalid choice! Try again.\n");
        }
    }
    while(choice!=6);
    return 0;
}
