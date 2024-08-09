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

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *val)
{
	int tmp = 0, valid = 0;

	while (!valid)
	{
		scanf("%d", &tmp);
		if (tmp <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			valid = 1;
			if (val != NULL)
			{
				*val = tmp;
			}
		}
	}

	return tmp;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *val)
{
	double tmp = 0.0;
	int valid = 0;

	while (!valid)
	{
		scanf("%lf", &tmp);
		if (tmp <= 0.0)
		{
			printf("ERROR: Enter a positive value: ");
		}
		else
		{
			valid = 1;
			if (val != NULL)
			{
				*val = tmp;
			}
		}
	}

	return tmp;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int prodNum)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", prodNum);
	printf("NOTE: A 'serving' is %dg\n\n", SERVING_GRAMS);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int prodSeqNum)
{
	struct CatFoodInfo info = {};
	printf("Cat Food Product #%d\n", prodSeqNum);
	printf("--------------------\n");
	printf("SKU           : ");
	info.skuId = getIntPositive(&info.skuId);
	printf("PRICE         : $");
	info.price = getDoublePositive(&info.price);
	printf("WEIGHT (LBS)  : ");
	info.weight = getDoublePositive(&info.weight);
	printf("CALORIES/SERV.: ");
	info.calories = getIntPositive(&info.calories);
	printf("\n");
	return info;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int skuId, const double *price, const int calories, const double *weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", skuId, *price, *weight, calories);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *lbs, double *kg)
{
	double tmp = *lbs / LBS_KG_CONVERSION_FACTOR;

	if (kg != NULL)
	{
		*kg = tmp;
	}

	return tmp;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *lbs, int *g)
{
	double tmp = *lbs * 1000 / LBS_KG_CONVERSION_FACTOR;
	if (g != NULL)
	{
		*g = tmp;
	}
	return tmp;
}

// 10. convert lbs: kg and g
void convertLbs(const double *lbs, double *kg, int *g)
{
	convertLbsKg(lbs, kg);
	convertLbsG(lbs, g);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int servingGrams, const int totalGrams, double *result)
{
	double tmp = (double)totalGrams / servingGrams;
	if (result != NULL)
	{
		*result = tmp;
	}
	return tmp;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *totalServing, double *result)
{
	double tmp = *price / *totalServing;
	if (result != NULL)
	{
		*result = tmp;
	}
	return tmp;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *totalCalories, double *result)
{
	double tmp = *price / *totalCalories;
	if (result != NULL)
	{
		*result = tmp;
	}
	return tmp;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo item)
{
	struct ReportData reportData;
	reportData.sku = item.skuId;
	reportData.price = item.price;
	reportData.calories = item.calories;
	reportData.lbs = item.weight;
	double tmp = reportData.calories;

	convertLbs(&item.weight, &reportData.kgs, &reportData.grams);
	calculateServings(SERVING_GRAMS, reportData.grams, &reportData.totalServing);
	calculateCostPerServing(&reportData.price, &reportData.totalServing, &reportData.costPerServing);
	calculateCostPerCal(&reportData.price, &tmp, &reportData.costPerCalories);

	return reportData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SERVING_GRAMS);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData data, int isCheapest)
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",
				 data.sku, data.price,
				 data.lbs, data.kgs, data.grams,
				 data.calories,
				 data.totalServing,
				 data.costPerServing,
				 data.costPerCalories / data.totalServing);
	isCheapest ? printf(" ***\n") : printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo item)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", item.skuId, item.price);
	printf("\n");
	printf("Happy shopping!\n");
	printf("\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start()
{
	int i;
	struct CatFoodInfo infoArray[MAX_PRODUCT_NUM] = {{}, {}, {}};

	openingMessage(MAX_PRODUCT_NUM);

	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		infoArray[i] = getCatFoodInfo(i + 1);
	}

	displayCatFoodHeader();

	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		displayCatFoodData(infoArray[i].skuId, &infoArray[i].price, infoArray[i].calories, &infoArray[i].weight);
	}

	int cheapestItemIndex = -1;
	struct ReportData reportDataArray[MAX_PRODUCT_NUM] = {{}, {}, {}};
	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		reportDataArray[i] = calculateReportData(infoArray[i]);
		if (cheapestItemIndex == -1 || reportDataArray[i].costPerServing < reportDataArray[cheapestItemIndex].costPerServing)
		{
			cheapestItemIndex = i;
		}
	}

	displayReportHeader();
	for (i = 0; i < MAX_PRODUCT_NUM; i++)
	{
		displayReportData(reportDataArray[i], i == cheapestItemIndex ? 1 : 0);
	}

	displayFinalAnalysis(infoArray[cheapestItemIndex]);
}