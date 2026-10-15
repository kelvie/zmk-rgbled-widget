#define SHOW_LAYER_CHANGE                                                                          \
    (IS_ENABLED(CONFIG_RGBLED_WIDGET_SHOW_LAYER_CHANGE)) &&                                        \
        (!IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))

#define SHOW_LAYER_COLORS                                                                          \
    (IS_ENABLED(CONFIG_RGBLED_WIDGET_SHOW_LAYER_COLORS)) &&                                        \
        (!IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL))

#if IS_ENABLED(CONFIG_ZMK_BATTERY_REPORTING)
void indicate_battery(void);
#endif

// Used by the endpoint listener on the central and by the split peripheral
// listener, so it must not be gated on CONFIG_ZMK_BLE: a split peripheral has
// BLE for the split link but no ZMK_BLE (no HID over GATT).
void indicate_connectivity(void);

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
void indicate_layer(void);
#endif
