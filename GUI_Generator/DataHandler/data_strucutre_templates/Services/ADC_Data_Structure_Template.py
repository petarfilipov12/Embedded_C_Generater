ADC_Data_Structure_Template = {
  "ADC_Service_ADCs": {
    "metadata": {
      "type": "Services/ADC/ADC_Service_ADCs",
      "mandatory": True,
      "deletable": False,
      "duplicable": False,
      "generate_params": False,
      "generate_data_count": True,
      "generate_data_data_files": True,
      "generate_data_data_files_data_type": "AdcCfg_t",
      "generate_data_data_files_data_name": "AdcHwCfg_data",
      "generate_data_data_files_init_func_postfix": "_INIT_FUNC",
    },
    "parameters": {
      "ShortName": {
        "value": "ADC_Service_ADCs",
        "metadata": {
          "type": "string",
          "changeable": False,
          "description": "Shortname for ADC_Service_ADCs container"
        }
      }
    },
    "data": {
      "ADC_Service_ADC": {
        "metadata": {
          "type": "Services/ADC/ADC_Service_ADCs/data/ADC_Service_ADC",
          "mandatory": False,
          "leaf": True,
          "deletable": True,
          "duplicable": True,
          "generate_params": True,
        },
        "parameters": {
          "ShortName": {
            "value": "ADC_Service_ADC",
            "metadata": {
              "type": "string",
              "changeable": True,
              "description": "Shortname for ADC_Service_ADC unit"
            }
          },
          "Id": {
            "value": "0",
            "metadata": {
              "id": True,
              "type": "int",
              "changeable": False,
              "description": "Unique Id number"
            }
          },
          "AdcBufferSize": {
            "value": "0",
            "metadata": {
              "type": "int",
              "gen_buffer": True,
              "gen_buffer_var_name": "adcBuffer",
              "gen_buffer_size_var_name": "adcBufferSize",
              "changeable": True,
              "description": "Size of ADC buffer in bytes"
            }
          }
        },
        "data": {}
      }
    }
  },
  "ADC_Service_Pins": {
    "metadata": {
      "type": "Services/ADC/ADC_Service_Pins",
      "mandatory": True,
      "deletable": False,
      "duplicable": False,
      "generate_params": False,
      "generate_data_count": True,
      "generate_data_data_files": True,
      "generate_data_data_files_data_type": "PinCfg_t",
      "generate_data_data_files_data_name": "AdcPinCfg_data",
      "generate_data_data_files_init_func_postfix": "_INIT_FUNC"
    },
    "parameters": {
      "ShortName": {
        "value": "ADC_Service_Pins",
        "metadata": {
          "type": "string",
          "changeable": False,
          "description": "Shortname for ADC_Service_Pins container"
        }
      }
    },
    "data": {
      "ADC_Service_Pin": {
        "metadata": {
          "type": "Services/ADC/ADC_Service_Pins/data/ADC_Service_Pin",
          "mandatory": False,
          "leaf": True,
          "deletable": True,
          "duplicable": True,
          "generate_params": True
        },
        "parameters": {
          "ShortName": {
            "value": "ADC_Service_Pin",
            "metadata": {
              "type": "string",
              "changeable": True,
              "description": "Shortname for ADC_Service_Pin"
            }
          },
          "Id": {
            "value": "0",
            "metadata": {
              "type": "int",
              "id": True,
              "changeable": False,
              "description": "Unique Id number"
            }
          },
          "AdcRef": {
            "value": "",
            "metadata": {
              "type": "reference",
              "reference_targets": [
                "Services/ADC/ADC_Service_ADCs"
              ],
              "changeable": True,
              "description": "Reference to ADC_Service_ADCs unit, which this pin will use"
            }
          }
        },
        "data": {}
      }
    }
  }
}