// -------------------------------------------------- //
// This file is autogenerated by pioasm; do not edit! //
// -------------------------------------------------- //

#pragma once

#if !PICO_NO_HARDWARE
#include "hardware/pio.h"
#endif

#define IRQ_RX_BS_ERR 1
#define IRQ_RX_EOP 2
#define IRQ_RX_START 3
#define USB_RX_START_OFFSET 1

// ----------- //
// usb_nrzi_rx //
// ----------- //

#define usb_nrzi_rx_wrap_target 3
#define usb_nrzi_rx_wrap 30

static const uint16_t usb_nrzi_rx_program_instructions[] = {
    0xc022, //  0: irq    wait 2                     
    0x00c1, //  1: jmp    pin, 1                     
    0xc103, //  2: irq    nowait 3               [1] 
            //     .wrap_target
    0xe046, //  3: set    y, 6                       
    0x00cb, //  4: jmp    pin, 11                    
    0x0072, //  5: jmp    !y, 18                     
    0x4061, //  6: in     null, 1                    
    0x01df, //  7: jmp    pin, 31                [1] 
    0x00df, //  8: jmp    pin, 31                    
    0x00df, //  9: jmp    pin, 31                    
    0x0113, // 10: jmp    19                     [1] 
    0xa0e0, // 11: mov    osr, pins                  
    0x6021, // 12: out    x, 1                       
    0x0040, // 13: jmp    x--, 0                     
    0x0290, // 14: jmp    y--, 16                [2] 
    0x0103, // 15: jmp    3                      [1] 
    0x4121, // 16: in     x, 1                   [1] 
    0x0004, // 17: jmp    4                          
    0xa642, // 18: nop                           [6] 
    0xe046, // 19: set    y, 6                       
    0x00da, // 20: jmp    pin, 26                    
    0x0097, // 21: jmp    y--, 23                    
    0x0613, // 22: jmp    19                     [6] 
    0xe021, // 23: set    x, 1                       
    0x4021, // 24: in     x, 1                       
    0x0514, // 25: jmp    20                     [5] 
    0xa0e0, // 26: mov    osr, pins                  
    0x6021, // 27: out    x, 1                       
    0x0040, // 28: jmp    x--, 0                     
    0x026f, // 29: jmp    !y, 15                 [2] 
    0x4161, // 30: in     null, 1                [1] 
            //     .wrap
    0x000a, // 31: jmp    10                         
};

#if !PICO_NO_HARDWARE
static const struct pio_program usb_nrzi_rx_program = {
    .instructions = usb_nrzi_rx_program_instructions,
    .length = 32,
    .origin = -1,
};

static inline pio_sm_config usb_nrzi_rx_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + usb_nrzi_rx_wrap_target, offset + usb_nrzi_rx_wrap);
    return c;
}
#endif

// ----------------- //
// usb_nrzi_rx_debug //
// ----------------- //

#define usb_nrzi_rx_debug_wrap_target 3
#define usb_nrzi_rx_debug_wrap 30

static const uint16_t usb_nrzi_rx_debug_program_instructions[] = {
    0xd822, //  0: irq    wait 2          side 1     
    0x00c1, //  1: jmp    pin, 1                     
    0xc103, //  2: irq    nowait 3               [1] 
            //     .wrap_target
    0xe046, //  3: set    y, 6                       
    0x00cb, //  4: jmp    pin, 11                    
    0x0072, //  5: jmp    !y, 18                     
    0x5061, //  6: in     null, 1         side 0     
    0x01df, //  7: jmp    pin, 31                [1] 
    0x00df, //  8: jmp    pin, 31                    
    0x00df, //  9: jmp    pin, 31                    
    0x0113, // 10: jmp    19                     [1] 
    0xa0e0, // 11: mov    osr, pins                  
    0x6021, // 12: out    x, 1                       
    0x0040, // 13: jmp    x--, 0                     
    0x0290, // 14: jmp    y--, 16                [2] 
    0x0103, // 15: jmp    3                      [1] 
    0x5921, // 16: in     x, 1            side 1 [1] 
    0x0004, // 17: jmp    4                          
    0xa642, // 18: nop                           [6] 
    0xe046, // 19: set    y, 6                       
    0x00da, // 20: jmp    pin, 26                    
    0x0097, // 21: jmp    y--, 23                    
    0x0613, // 22: jmp    19                     [6] 
    0xe021, // 23: set    x, 1                       
    0x5821, // 24: in     x, 1            side 1     
    0x0514, // 25: jmp    20                     [5] 
    0xa0e0, // 26: mov    osr, pins                  
    0x6021, // 27: out    x, 1                       
    0x0040, // 28: jmp    x--, 0                     
    0x026f, // 29: jmp    !y, 15                 [2] 
    0x5161, // 30: in     null, 1         side 0 [1] 
            //     .wrap
    0x000a, // 31: jmp    10                         
};

#if !PICO_NO_HARDWARE
static const struct pio_program usb_nrzi_rx_debug_program = {
    .instructions = usb_nrzi_rx_debug_program_instructions,
    .length = 32,
    .origin = -1,
};

static inline pio_sm_config usb_nrzi_rx_debug_program_get_default_config(uint offset) {
    pio_sm_config c = pio_get_default_sm_config();
    sm_config_set_wrap(&c, offset + usb_nrzi_rx_debug_wrap_target, offset + usb_nrzi_rx_debug_wrap);
    sm_config_set_sideset(&c, 2, true, false);
    return c;
}

#include "hardware/clocks.h"
static __always_inline void pio_sm_set_jmp_pin(PIO pio, uint sm, uint jmp_pin) {
  pio->sm[sm].execctrl =
      (pio->sm[sm].execctrl & ~PIO_SM0_EXECCTRL_JMP_PIN_BITS) |
      (jmp_pin << PIO_SM0_EXECCTRL_JMP_PIN_LSB);
}
static inline void usb_rx_fs_program_init(PIO pio, uint sm, uint pin_dp, uint pin_dm, bool is_fs, int pin_debug) {
  if (pin_dp < pin_dm) {
    pio_sm_set_consecutive_pindirs(pio, sm, pin_dp, 2, false);
  } else {
    pio_sm_set_consecutive_pindirs(pio, sm, pin_dm, 2, false);
  }
  gpio_pull_down(pin_dp);
  gpio_pull_down(pin_dm);
  gpio_set_inover(pin_dp, GPIO_OVERRIDE_INVERT);
  gpio_set_inover(pin_dm, GPIO_OVERRIDE_INVERT);
  pio_sm_config c;
  if (pin_debug < 0) {
    c = usb_nrzi_rx_program_get_default_config(0);
  } else {
    c = usb_nrzi_rx_debug_program_get_default_config(0);
    pio_sm_set_pins_with_mask(pio, sm, 0, 1 << pin_debug);
    pio_sm_set_pindirs_with_mask(pio, sm, 1 << pin_debug, 1 << pin_debug);
    pio_gpio_init(pio, pin_debug);
    sm_config_set_sideset_pins(&c, pin_debug);
  }
  sm_config_set_in_pins(&c, pin_dp);  // for WAIT, IN
  sm_config_set_jmp_pin(&c, pin_dm);  // for JMP
  // Shift to right, autopull enabled, 8bit
  sm_config_set_in_shift(&c, true, true, 8);
  sm_config_set_fifo_join(&c, PIO_FIFO_JOIN_RX);
  float div;
  if (is_fs) {
    div = (float)clock_get_hz(clk_sys) / (120000000);
  } else {
    div = (float)clock_get_hz(clk_sys) / (15000000);
  }
  sm_config_set_clkdiv(&c, div);
  pio_sm_init(pio, sm, 1, &c);
  pio_sm_set_enabled(pio, sm, true);
}

#endif

