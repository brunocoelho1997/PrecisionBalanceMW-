#include "PrecisionBalanceLogic.h"


  PrecisionBalanceLogic::PrecisionBalanceLogic(){    
    
    
  }

  

  void PrecisionBalanceLogic::getRawValuesFromCells(double *rawValuesFromCellsArray[], HX711 cells[], int numberOfCells)
  {
    *rawValuesFromCellsArray = new double[numberOfCells];
    int i;
    for (i = 0; i < NUMBER_OF_CELLS; i = i + 1) {
      (*rawValuesFromCellsArray)[i] = cells[i].get_units(NUMBER_OF_READINGS);
    }

    (*rawValuesFromCellsArray)[16] = 0; //to indicate that raw cells data will not be exported

  }

  void PrecisionBalanceLogic::calibrateCell(HX711 *cell, int loadcellDoutPin, int loadCellSckPin, float calibrationFactor)
  {
    cell->begin(loadcellDoutPin, loadCellSckPin);
    cell->set_scale(calibrationFactor);
    cell->tare();
  }

  void PrecisionBalanceLogic::tareCells(HX711 cells[])
  {
    int i;
    for (i = 0; i < NUMBER_OF_CELLS; i = i + 1) {
      cells[i].tare();
    }
  }


  //unused method
//  double PrecisionBalanceLogic::getMeanValuesFromCellGroup(char group)
//  {
//    double weight;
//
//    switch(group) {
//      case 'A':
//        weight = cells[0].get_units(NUMBER_OF_READINGS);
//        weight += cells[1].get_units(NUMBER_OF_READINGS);
//        weight += cells[2].get_units(NUMBER_OF_READINGS);
//        weight += cells[3].get_units(NUMBER_OF_READINGS);
//        break;
//        
//      case 'B':
//        weight = cells[4].get_units(NUMBER_OF_READINGS);
//        weight += cells[5].get_units(NUMBER_OF_READINGS);
//        weight += cells[6].get_units(NUMBER_OF_READINGS);
//        weight += cells[7].get_units(NUMBER_OF_READINGS);
//        break;      
//    }
//
//    return weight/4;
//    
//  }
  
