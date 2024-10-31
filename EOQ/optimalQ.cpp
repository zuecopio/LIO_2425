/**
 * @file     optimal_Q.cpp
 *
 * @author   Marcos Belda Martinez' <mbelmar@etsinf.upv.es>
 * @date     November, 2024
 * @section  LIO-GIIROB
 * @brief    This program calculates the optimal Q given a demand D of the
 *           items defined in references.h
 */

//-----[ INCLUDES ]-----------------------------------------------------------//

#include "references.h"

#include <iostream>
#include <iomanip> // Para std::setw
#include <math.h>
#include <unordered_map>
#include <vector>
#include <limits> // Para std::numeric_limits

using namespace std;

//-----[ COLORS ]-------------------------------------------------------------//

#define RESET_COLOR	"\e[0m"
#define BOLD        "\e[1;37m"
#define CYAN_T   	"\e[1;36m"
#define YELLOW   	"\e[1;33m"
#define WHITE       "\e[1;37m"
#define RED         "\e[0;31m"

//-----[ IMPLEMENTATION OF THE FUNCTION ]-------------------------------------//

/******************************************************************************/
/*!
 * @brief  Method that calculates the Q* of a reference given
 *         a specific Annual Demand (D). It shows a table with
 *         the values ​​of ce, ca, cp, Q*, CA, CE, CP and CT.
 * @param  D  This number indicates the annual demand for the reference.
 * @param  item  Pointer to reference.
 * @return void
 */
void showOptimalQ(int D, reference_t * item)
{
    float optimal_Q = 0.0;
    float optimal_ca, optimal_ce, optimal_cp, min_CA, optimal_CE, optimal_CP;
    float min_CT = MAXFLOAT;

    for (int i = 1; i <= (D * 2); i++)
    {
        // Find ca
        float ca;
        for (int j = 0; j < (item->ca_list).size(); j++)
        {
            if ((i >= (item->ca_list[j]).min_unit) && 
                (((i < (item->ca_list[j + 1]).min_unit) ||
                  (j + 1 == ((item->ca_list).size())))))
            {
                ca = (item->ca_list[j]).value; 
            }         
        }

        // Find ce
        float ce;
        for (int j = 0; j < (item->ce_list).size(); j++)
        {
            if ((i >= (item->ce_list[j]).min_unit) && 
                (((i < (item->ce_list[j + 1]).min_unit) ||
                  (j + 1 == ((item->ce_list).size())))))
            {
                ce = ((item->ce_list[j]).value); 
            }         
        }

        // Find cp
        float cp = item->cp_percentage * ca;

        // Calculate CA
        float CA = ca * (D * 1.0);

        // Calculate CE
        float CE = ce * ((D * 1.0) / (i * 1.0));

        // Calculate CP
        float CP = cp * ((i * 1.0) / 2.0);

        // Calculate CT
        float CT = CA + CE + CP;

        // If the calculated CT is less than min_CT, update the values
        if (CT < min_CT)
        {
            optimal_Q = i;
            
            optimal_ca = ca;
            optimal_ce = ce;
            optimal_cp = cp;
            min_CA = CA;
            optimal_CE = CE;
            optimal_CP = CP;
            min_CT = CT;
        }
    }

    cout << endl;

    // Set the format to display three decimal precision
    cout << fixed << setprecision(3);

    cout << "+-------------------+" << endl;
    cout << "| ca: " << setw(9) << optimal_ca << " €   |" << endl;
    cout << "| ce: " << setw(9) << optimal_ce << " €   |" << endl;
    cout << "| cp: " << setw(9) << optimal_cp << " €   |" << endl;
    cout << "|-------------------|" << endl;

    // Set the format to display zero decimal precision
    cout << fixed << setprecision(0);

    cout << "| " << BOLD << "Q*: " << setw(9) << optimal_Q;
    cout << " ud. " << RESET_COLOR << "|" << endl;
    cout << "|-------------------|" << endl;

    // Set the format to display two decimal precision
    cout << fixed << setprecision(2);

    cout << "| CA: " << setw(9) << min_CA << " €   |" << endl;
    cout << "| CE: " << setw(9) << optimal_CE << " €   |" << endl;
    cout << "| CP: " << setw(9) << optimal_CP << " €   |" << endl;
    cout << "|-------------------|" << endl;
    cout << "| CT: " << setw(9) << min_CT << " €   |" << endl;
    cout << "+-------------------+" << endl;

    cout << endl;

}   /* showOptimalQ() */

/******************************************************************************/
/*!
 * @brief  Main program that displays a simple
 *         graphical interface through the terminal.
 * @param  void
 * @return void
 */
int main(void)
{
    // Create dictionary of references
    unordered_map<string, reference_t> referencesDict;

    // Add all references from (references.h) to the dictionary
    referencesDict.insert({     "NVLS745", R_NVLS745    });
    referencesDict.insert({      "110212", R_110212     });
    referencesDict.insert({   "260024045", R_260024045  });
    referencesDict.insert({   "260024046", R_260024046  });
    referencesDict.insert({      "303117", R_303117     });
    referencesDict.insert({      "110102", R_110102     });
    referencesDict.insert({      "110207", R_110207     });
    referencesDict.insert({     "CAJ1205", R_CAJ1205    });
    referencesDict.insert({    "STO69015", R_STO69015   });
    referencesDict.insert({  "tapon-PP28", R_taponPP28  });
    referencesDict.insert({  "CUDOS/1000", R_CUDOS1000  });
    referencesDict.insert({  "30ml-DIN18", R_30mlDIN18  });
    referencesDict.insert({ "tapon-spray", R_taponspray });
    referencesDict.insert({     "caja_01", R_caja_01    });
    referencesDict.insert({     "caja_02", R_caja_02    });
    referencesDict.insert({     "caja_03", R_caja_03    });
    referencesDict.insert({     "caja_04", R_caja_04    });  

    // Create the rest of the necessary variables
    string itemName;
    bool referenceIsValid = false;
    unordered_map<string, reference_t>::iterator searched;
    int demanda;
    bool demandIsValid = false;
 
    system("clear");

    for(;;)
    {
        // Show references table to user
        cout << "+--------------------------------------------------------------+" << endl;
        cout << "| " << BOLD << "TABLA DE REFERENCIAS" << RESET_COLOR;
        cout << "                                         |" << endl;
        cout << "+-------------+------------------------------------------------+" << endl;
        cout << "| " << BOLD << "ID" << RESET_COLOR;
        cout << "          | " << BOLD << "Descripción" << RESET_COLOR;
        cout << "                                    |" << endl;
        cout << "+-------------+------------------------------------------------+" << endl;
        cout << "| NVLS745     | Envase de miel  1 kg liso V720                 |" << endl;
        cout << "| 110212      | Tapa TO 77mm dorada pasteurizable              |" << endl;
        cout << "| 260024045   | Rollo de 500 etiquetas (de cualquier tipo)     |" << endl;
        cout << "| 260024046   | Rollo de 1000 etiquetas de precinto para botes |" << endl;
        cout << "| 303117      | Caja de cartón para 12 tarros V720             |" << endl;
        cout << "| 110102      | Envase de 0,5 kg celdilla                      |" << endl;
        cout << "| 110207      | Tapa TO 66 mm dorada pasteurizable             |" << endl;
        cout << "| CAJ1205     | Caja de cartón 12 frascos miel 1/2 kg          |" << endl;
        cout << "| STO69015    | Topacio 20 ml para jalea PP28 sin tapón        |" << endl;
        cout << "| tapon-PP28  | Tapón PP28 para topacios                       |" << endl;
        cout << "| CUDOS/1000  | Cuchara para jalea real 1000 ud.               |" << endl;
        cout << "| 30ml-DIN18  | Topacio ámbar para propóleos 30 ml DIN18       |" << endl;
        cout << "| tapon-spray | Tapón spray de envase para propoleo            |" << endl;
        cout << "| caja_01     | Embalajes para jalea real                      |" << endl;
        cout << "| caja_02     | Caja de cartón para 24 de jalea real           |" << endl;
        cout << "| caja_03     | Embalajes para propóleo                        |" << endl;
        cout << "| caja_04     | Caja de cartón para 24 de propóleo             |" << endl;
        cout << "+-------------+------------------------------------------------+" << endl;
        cout << " *Para copiar una referencia usar CTRL + SHIFT + C                 " << endl;
        cout << " *Para pegar usar CTRL + SHIFT + V                                 " << endl;

        do
        {
            // Ask which reference is wanted to calculate the Q* from
            cout << endl << BOLD << " -> ¿Sobre qué ítem calcular la Q*? ";
            cout << "(escribir ID): " << RESET_COLOR;
            cin >> itemName;
            
            // Find reference
            searched = referencesDict.find(itemName);
            
            // Check if the key is not present
            if (searched == referencesDict.end())
            {
                // If not, retry
                cout << RED << " -> La referencia '" << itemName;
                cout << "' no está en el diccionario." << RESET_COLOR << endl;
            }
            else
            {
                // If it exists, exit the query loop
                referenceIsValid = true;
            }

        } while (referenceIsValid == false);
    
        // Request the value of the Annual Demand (D)
        cout << BOLD << " -> ¿Cuánta es la Demanda Anual?: " << RESET_COLOR;
        
        do
        {            
            cin >> demanda;

            // Check if the entry was successful
            if (cin.fail())
            {
                // Clear the error state
                cin.clear();
                // Ignore bad input
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << RED << " -> Por favor, ingresa un ";
                cout << "número entero válido: " << RESET_COLOR;
            }
            else
            {
                // If the entry was successful, exit the loop
                demandIsValid = true;
            }   

        } while (demandIsValid == false);
        
        // Calculate and display the Q*
        showOptimalQ(demanda, &(searched->second));
        
        // Wait for the user to press any key
        cout << BOLD << " -> Presiona ENTER para continuar,";
        cout << " o CTRL + C para salir..." << RESET_COLOR;
        getchar();
        getchar();
        cout << endl << endl;
    }

    return 0;

}   /* main() */

/*** end of file ***/