#include <iostream>

using namespace std;


double calculate_price_years(int years, int main_price, double percentage_of_year);

double calculate_price_kilometers(double kilometers, int price_years, double percentage_of_kilometers);

double calculate_price_big_crashes(int number_big_crashes, double price_kilometers, double percentage_big_crashes);



int main()

{
    //first identified the variable vehicle_brand
    int vehicle_brand;
    //here we are asking the user to enter the the number that represent the vehicle brand
    cout << "can you please choose the number that represents the brand of your vehicle\n";

    cout << " 1. KIA \n 2. MAZDA \n 3. LANCER \n 4. PORCHE \n 5. HONDA \n";
    //we used cin here to take the input from the user that represents the vehicle brand
    cin >> vehicle_brand;


    int price_of_KIA = 407900;
    int  price_of_MAZDA = 700000;
    int price_of_LANCER = 1577690;
    int price_of_PORCHE = 2549000;
    int  price_of_HONDA = 726200;




    while (vehicle_brand > 5 || vehicle_brand < 1)

    {

        cout << "option is not found please enter another option from 1 to 5 \n";

        cout << endl;

        cout << "can you please choose the number that represents the brand of your vehicle \n";

        cout << " 1. KIA \n 2. MAZDA \n 3. LANCER \n 4. PORCHE \n 5. HONDA \n";

        cin >> vehicle_brand;

    }
    int data = 0;

    int counter = 0;

    int model_vehicle;


    int main_price;

    int sell_year;

    double kilometers = 0.0;

    double percentage_of_year = 0.0;

    double percentage_of_kilometers = 0.0;


    double percentage_big_crashes = 0.0;





    // here iam using the [if]to make sure that the gets the main price of the vehicle that the user choose
    if (vehicle_brand == 1)
    {
        main_price = 407900;
        percentage_of_year = 3.5;
        percentage_of_kilometers = 3.1;
        percentage_big_crashes = 2.5;


    }
    else if (vehicle_brand == 2)
    {
        main_price = 700000;
        percentage_of_year = 3.5;
        percentage_of_kilometers = 2.6;
        percentage_big_crashes = 2.5;
    }
    else if (vehicle_brand == 3)
    {
        main_price = 1577690;
        percentage_of_year = 4.0;
        percentage_of_kilometers = 3.3;
        percentage_big_crashes = 2.2;
    }
    else if (vehicle_brand == 4)
    {
        main_price = 2549000;
        percentage_of_year = 3.7;
        percentage_of_kilometers = 2.0;
        percentage_big_crashes = 2.7;
    }
    else
    {
        main_price = 726200;
        percentage_of_year = 4.1;
        percentage_of_kilometers = 3.2;
        percentage_big_crashes = 1.7;
    }



    //iam asking the user what is the year model of his vehicle
    cout << "can you Please enter the year of model of your vehicle \n";

    cin >> model_vehicle;

    //iam asking the user what year he wants to sell his car
    cout << "In what year do you want to sell your vehicle ? \n";

    cin >> sell_year;

    //this line is to calculate the number of years the user has used the car
    int years = sell_year - model_vehicle;

    //here iam  calling the function to calculate the price after n years.

    double price_years = calculate_price_years(years, main_price, percentage_of_year);




    //asking the user how many kilometers did his car move
    cout << "can you please tell me How many kilometers did your car move? \n";

    cin >> kilometers;


    // here iam calling the function to calculate the price after n kilometers.

    double price_kilometers = calculate_price_kilometers(kilometers, price_years, percentage_of_kilometers);



    int number_big_crashes = 0;

    double price_big_crashes;

   


    char crashes_big;

    cout << "Did the car face any  accidents? \n";

    cout << "Please enter either 'y' for yes or 'n' for no \n";

    cin >> crashes_big;





    // calling the function to calculate the price after n big accidents

    if (crashes_big == 'y' || crashes_big == 'Y')

    {

        cout << "How many  accidents did the car face? \n";

        cin >> number_big_crashes;



        price_big_crashes = calculate_price_big_crashes(number_big_crashes, price_kilometers, percentage_big_crashes);


    }

    else if (crashes_big == 'n' || crashes_big == 'N')

    {

        price_big_crashes = price_kilometers;


    }





    int condition;

    cout << " what is the condition of the vheicle  interior ?\n";
    cout << " 1.pristine \n 2.average \n 3.poor \n ";
    cout << " please choose the number that represents your condition\n";
    cin >> condition;


    switch (condition)
    {
    case 1:
        cout << " your car is in pristine condition nothing will de deducted from the price  \n";
        break;

    case 2:
        cout << "your car is in average condition so we are going to take 2% of the price\n";
        price_big_crashes = (price_big_crashes-((0.2) * price_big_crashes));
        break;

    case 3:
        cout << "your car is in a poor condition so we are going to take 4% of the price \n";
        price_big_crashes = (price_big_crashes-((0.4) * price_big_crashes) );
        break;

    default:
        cout << "please enter number 1 or 2 or 3 \n";
        break;
    }


    cout << "The price that you can sell the car with is " << price_big_crashes << "\n";

    cout << "This price is not final. The final price will be determined after the technical inspection of the vheicle \n";

    int ch;
    cout << "do you want to repeat the procecss?\n";
    cout << " please choos the number of your answer\n";
    cout << " 1. yes \n 2. no \n";

    cin >> ch;
    //i puted a switch case here for the user to repeat the process 
    switch (ch) {
    case 1:
        //if he choosed 1 so the system will close and return back to main
        system("cls");
        main();
        break;
    case 2:
        //if he choosed 2 so the process will end 
        exit(0);

    }

    return 0;
}

//a function to subtract percentage_years of the initial price (main_price) from (main_price), for each year.



double calculate_price_years(int years, int main_price, double percentage_of_year)

{

    return ((1-((percentage_of_year/100)*years) / 100) * main_price);

}





//a function to subtract percentage_kilometers percent of the price after n years (price_years) from (price_years), for each 100000 kilometers.

double calculate_price_kilometers(double kilometers, int price_years, double percentage_of_kilometers)

{
    return  ((1-((percentage_of_kilometers/100) *( kilometers / 1000000)))*price_years) ;



}







// if the accidents are big, for one big accident subtract percentage_big_accidents from the price after n big accidents

double calculate_price_big_crashes(int number_big_crashes, double price_kilometers, double percentage_big_crashes)

{

    return ( (1-((percentage_big_crashes/100) * number_big_crashes))*price_kilometers );

}