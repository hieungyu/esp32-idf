idf_component_register(SRCS "led7digit.c"
                    PRIV_REQUIRES spi_flash driver)

target_include_directories(${COMPONENT_LIB} PUBLIC ".")
