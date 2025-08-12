import java.util.Scanner;

class TravelPackage
{
    String TravelCode;
    int NoOfAdults;
    int NoOfKids;
    int Kilometer;
    float TotalFare;

    TravelPackage()
    {
        TravelCode = "NULL";
        NoOfAdults = 0;
        NoOfKids = 0;
        Kilometer = 0;
        TotalFare = 0.0f;
    }

    void AssignFare()
    {
        int farePerAdult;
        if (Kilometer >= 1000)
        {
            farePerAdult = 500;
        }
        else if (Kilometer < 1000 && Kilometer >= 500)
        {
            farePerAdult = 300;
        }
        else
        {
            farePerAdult = 200;
        }

        float totalAdultFare = (NoOfAdults * farePerAdult);

        float totalKidFare = (NoOfKids * (farePerAdult / 2.0f));

        TotalFare = (totalAdultFare + totalKidFare);
    }

    void EnterTour(String code, int adults, int kids, int kms)
    {
        TravelCode = code;
        NoOfAdults = adults;
        NoOfKids = kids;
        Kilometer = kms;

        AssignFare();
    }

    void ShowTour()
    {
        System.out.println("...........TOUR PACKAGE DETAILS............");
        System.out.println("TRAVEL CODE: " + TravelCode);
        System.out.println("NUMBER OF ADULTS: " + NoOfAdults);
        System.out.println("NUMBER OF KIDS: " + NoOfKids);
        System.out.println("KILOMETERS: " + Kilometer);
        System.out.println("TOTAL FARE: " + TotalFare);
    }
}

class TravelMain
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        TravelPackage tp = new TravelPackage();

        System.out.println("Enter Travel Code:");
        String code = sc.nextLine();

        System.out.println("Enter number of Adults:");
        int adults = sc.nextInt();

        System.out.println("Enter number of Kids:");
        int kids = sc.nextInt();

        System.out.println("Enter distance in kilometers:");
        int kms = sc.nextInt();

        tp.EnterTour(code, adults, kids, kms);
        tp.ShowTour();
    }
}