/*
 * ADC_Task.hpp
 *
 *  Reads the ADC input values coming from the accelerometer, calculates the angle between g and x and z axis
 *      and sends those angles to the LCD Task using the mailbox
 *
 *  Created on: Aug 31, 2016
 *      Author: eortiz
 */

#ifndef ADC_TASK_HPP_ 
#define ADC_TASK_HPP_
#define __NOP __nop // PREGUNTAR
#define PI 3.14159265

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "Task.hpp" // Includes parent class
#include "Mailbox.hpp"
#include <math.h>

class ADC_Task : public Task // clase heredada de tipo Task
{
    public:
        
        // Constructor prototype
        ADC_Task(Mailbox *i_ptrMailbox);
        // run prototype (inherited from the class task)
        virtual uint8_t run(void); 

        // setup prototype (inherited from the class task)
        virtual uint8_t setup(void); 

        // Creates and post a message for the LCD task
        uint8_t m_CreateAndPostMsg(void);
        uint16_t m_GetAngle(uint16_t i_u16Axis);

    private:
        Mailbox *m_ptrMailbox;  // Pointer to mailbox
        uint16_t m_u16ResultsBuffer[32];    // Buffer for the conversion result values
    protected:
};

#endif /* LED_HPP_ */  //TERMINA EL IF
 
