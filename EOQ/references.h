/**
 * @file     references.h
 *
 * @author   Marcos Belda Martinez' <mbelmar@etsinf.upv.es>
 * @date     November, 2024
 * @section  LIO-GIIROB
 * @brief    Definition of the references used in optimalQ.cpp.
 */

//-----[ INCLUDES ]-----------------------------------------------------------//

#include <iostream>
#include <vector>

using namespace std;

//-----[ TYPEDEF STRUCTS ]----------------------------------------------------//

typedef struct
{
    int min_unit;
    float value;
    
} cost_t;

typedef struct
{
    string id;
    string description;
    vector<cost_t> ca_list;
    vector<cost_t> ce_list;
    float cp_percentage;

} reference_t;

//-----[ REFERENCES ]---------------------------------------------------------//

/*--------------------------------------------------+
 |     NVLS745 - Envase de miel  1 kg liso V720     |
 +--------------------------------------------------*/

reference_t R_NVLS745 =
{
    // Product ID
    "NVLS745",
    // Product description
    "Envase de miel  1 kg liso V720",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {    1, 0.55 },
        {   50, 0.54 },
        {  150, 0.53 },
        { 1176, 0.34 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {    1,   3.95 },
        {    7,   4.95 },
        {   38,   5.90 },
        {   60,   6.95 },
        {   75,   8.89 },
        {  115,  14.90 },
        {  186,  16.90 },
        {  223,  18.76 },
        {  256,  25.89 },
        {  334,  29.98 },
        {  445,  48.40 },
        {  482,  59.29 },
        { 2223, 119.79 },
        { 4815, 227.48 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.16
};

/*----------------------------------------------------+
 |     110212 - Tapa TO 77mm dorada pasteurizable     |
 +----------------------------------------------------*/

reference_t R_110212 =
{
    // Product ID
    "110212",
    // Product description
    "Tapa TO 77mm dorada pasteurizable",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {    1, 0.18 },
        {  100, 0.17 },
        {  200, 0.16 },
        {  950, 0.12 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {    1,   3.95 },
        {  200,   4.95 },
        { 1000,   5.90 },
        { 1600,   6.95 },
        { 2000,   8.89 },
        { 3000,  14.90 },
        { 5001,  16.90 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.10
};

/*----------------------------------------------------------------+
 |     260024045 - Rollo de 500 etiquetas (de cualquier tipo)     |
 +----------------------------------------------------------------*/

reference_t R_260024045 =
{
    // Product ID
    "260024045",
    // Product description
    "Rollo de 500 etiquetas (de cualquier tipo)",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {    1, 24.95}
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {    1,   3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.09
};

/*--------------------------------------------------------------------+
 |     260024046 - Rollo de 1000 etiquetas de precinto para botes     |
 +--------------------------------------------------------------------*/

reference_t R_260024046 =
{
    // Product ID
    "260024046",
    // Product description
    "Rollo de 1000 etiquetas de precinto para botes",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {    1, 29.95}
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {    1,   3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.09
};

/*-----------------------------------------------------+
 |     303117 - Caja de cartón para 12 tarros V720     |
 +-----------------------------------------------------*/

reference_t R_303117 =
{
    // Product ID
    "303117",
    // Product description
    "Caja de cartón para 12 tarros V720",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {   1, 0.65 },
        { 100, 0.55 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {     1,   3.95 },
        {    20,   4.95 },
        {   100,   5.90 },
        {   160,   6.95 },
        {   200,   8.89 },
        {   310,  14.90 },
        {   501,  16.90 },
        {   600,  18.76 },
        {   690,  25.89 },
        {   900,  29.98 },
        {  1200,  48.40 },
        {  1300,  59.29 },
        {  6000, 119.79 },
        { 13000, 227.48 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.14
};

/*--------------------------------------------+
 |     110102 - Envase de 0,5 kg celdilla     |
 +--------------------------------------------*/

reference_t R_110102 =
{
    // Product ID
    "110102",
    // Product description
    "Envase de 0,5 kg celdilla",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {    1, 0.45 },
        {  100, 0.43 },
        {  500, 0.41 },
        { 1040, 0.37 },
        { 2097, 0.27 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {    1,   3.95 },
        {    7,   4.95 },
        {   35,   5.90 },
        {   56,   6.95 },
        {   69,   8.89 },
        {  107,  14.90 },
        {  173,  16.90 },
        {  207,  18.76 },
        {  238,  25.89 },
        {  311,  29.98 },
        {  414,  48.40 },
        {  449,  59.29 },
        { 2069, 119.79 },
        { 4483, 227.48 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.15
};

/*-----------------------------------------------------+
 |     110207 - Tapa TO 66 mm dorada pasteurizable     |
 +-----------------------------------------------------*/

reference_t R_110207 =
{
    // Product ID
    "110207",
    // Product description
    "Tapa TO 66 mm dorada pasteurizable",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {    1, 0.18 },
        {  300, 0.16 },
        { 1500, 0.12 },
        { 2500, 0.10 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {    1,   3.95 },
        {  250,   4.95 },
        { 1250,   5.90 },
        { 2000,   6.95 },
        { 2500,   8.89 },
        { 3875,  14.90 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.10
};

/*---------------------------------------------------------+
 |     CAJ1205 - Caja de cartón 12 frascos miel 1/2 kg     |
 +---------------------------------------------------------*/

reference_t R_CAJ1205 =
{
    // Product ID
    "CAJ1205",
    // Product description
    "Caja de cartón 12 frascos miel 1/2 kg",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        { 1, 0.65 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {    1,   3.95 },
        {   10,   4.95 },
        {   50,   5.90 },
        {   80,   6.95 },
        {  100,   8.89 },
        {  155,  14.90 },
        {  251,  16.90 },
        {  300,  18.76 },
        {  345,  25.89 },
        {  450,  29.98 },
        {  600,  48.40 },
        {  650,  59.29 },
        { 3000, 119.79 },
        { 6500, 227.48 },
        { 9715, 286.77 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.13
};

/*------------------------------------------------------------+
 |     STO69015 - Topacio 20 ml para jalea PP28 sin tapón     |
 +------------------------------------------------------------*/

reference_t R_STO69015 =
{
    // Product ID
    "STO69015",
    // Product description
    "Topacio 20 ml para jalea PP28 sin tapón",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {   1, 0.26 },
        { 156, 0.18 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        { 1, 3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.13
};

/*-----------------------------------------------+
 |     tapon-PP28 - Tapón PP28 para topacios     |
 +-----------------------------------------------*/

reference_t R_taponPP28 =
{
    // Product ID
    "tapon-PP28",
    // Product description
    "Tapón PP28 para topacios",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        { 1, 0.14 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        { 1, 3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.10
};

/*------------------------------------------------------+
 |     CUDOS/1000 - Cuchara para jalea real 1000 ud.    |
 +------------------------------------------------------*/

reference_t R_CUDOS1000 =
{
    // Product ID
    "CUDOS/1000",
    // Product description
    "Cuchara para jalea real 1000 ud.",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        { 1, 24.90 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {     1, 3.95 },
        {  2000, 4.95 },
        { 10000, 5.90 },
        { 16000, 6.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.09
};

/*--------------------------------------------------------------+
 |     30ml-DIN18 - Topacio ámbar para propóleos 30 ml DIN18    |
 +--------------------------------------------------------------*/

reference_t R_30mlDIN18 =
{
    // Product ID
    "30ml-DIN18",
    // Product description
    "Topacio ámbar para propóleos 30 ml DIN18",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {   1, 0.37 },
        { 115, 0.27 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {     1, 3.95 },
        {  2000, 4.95 },
        { 10000, 5.90 },
        { 16000, 6.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.13
};

/*-----------------------------------------------------------+
 |     tapon-spray - Tapón spray de envase para propoleo     |
 +-----------------------------------------------------------*/

reference_t R_taponspray =
{
    // Product ID
    "tapon-spray",
    // Product description
    "Tapón spray de envase para propoleo",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {   1, 0.69 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {  1, 5.99 },
        { 66, 0.00 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.08
};

/*---------------------------------------------+
 |     caja_01 - Embalajes para jalea real     |
 +---------------------------------------------*/

reference_t R_caja_01 =
{
    // Product ID
    "caja_01",
    // Product description
    "Embalajes para jalea real",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        {   1, 0.15 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        {  1, 3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.10
};

/*--------------------------------------------------------+
 |     caja_02 - Caja de cartón para 24 de jalea real     |
 +--------------------------------------------------------*/

reference_t R_caja_02 =
{
    // Product ID
    "caja_02",
    // Product description
    "Caja de cartón para 24 de jalea real",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        { 1, 0.55 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        { 1, 3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.12
};

/*-------------------------------------------+
 |     caja_03 - Embalajes para propóleo     |
 +-------------------------------------------*/

reference_t R_caja_03 =
{
    // Product ID
    "caja_03",
    // Product description
    "Embalajes para propóleo",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        { 1, 0.15 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        { 1, 3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.10
};

/*------------------------------------------------------+
 |     caja_04 - Caja de cartón para 24 de propóleo     |
 +------------------------------------------------------*/

reference_t R_caja_04 =
{
    // Product ID
    "caja_04",
    // Product description
    "Caja de cartón para 24 de propóleo",
    // Acquisition Cost {Minimum Units, Price per Unit}
    {
        { 1, 0.55 }
    },
    // Cost of Issue {Minimum Units, Price per Unit}
    {
        { 1, 3.95 }
    },
    // Cost of ownership (% of Acquisition Cost)
    0.12
};

/*** end of file ***/