/******************************************************************************/
/*                                                                            */
/******************************************************************************/

#include <stdbool.h>


typedef enum
{
   INPUT_CH_A_128 = 25,
   INPUT_CH_B_32,
   INPUT_CH_A_64
}hx711_mode_t;

typedef  enum
{
  DATA_READY,
  DATA_ERROR
}hx711_evt_t;
 

typedef void (*hx711_event_handler_t)(hx711_evt_t evt, int value);


void hx711_init(hx711_mode_t mode, hx711_event_handler_t evt_handler);

void hx711_start(bool single);

void hx711_stop();

void hx711_power_down();
