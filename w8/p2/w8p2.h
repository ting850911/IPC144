/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
Full Name  : Nina Wang
Student ID#: 148817232
Email      : ytwang4@myseneca.ca
Section    : NAA

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

// ----------------------------------------------------------------------------
// defines/macros
#define MAX_PRODUCT_NUM 3
#define SERVING_GRAMS 64
#define LBS_KG_CONVERSION_FACTOR 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo
{
  int skuId;     // skuId is product sku
  double price;  // product is the product price
  int calories;  // calories is calories per suggested serving
  double weight; // weight is product weight in pounds
};

struct ReportData
{
  int sku;                // product sku number
  double price;           // product price
  double lbs;             // product weight in pounds (lbs)
  double kgs;             // product weight in kilograms (kg)
  int grams;              // product weight in grams (g)
  int calories;           // calories per suggested serving
  double totalServing;    // total servings
  double costPerServing;  // cost per serving
  double costPerCalories; // cost of calories per serving
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *val);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *val);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int prodNum);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int prodSeqNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuId, const double *price, const int calories, const double *weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *lbs, double *kgs);

// 9. convert lbs: g
int convertLbsG(const double *lbs, int *grams);

// 10. convert lbs: kg / g
void convertLbs(const double *lbs, double *kgs, int *grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingGrams, const int totalGrams, double *result);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *totalServing, double *result);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *totalCalories, double *result);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo item);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo item);

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void);