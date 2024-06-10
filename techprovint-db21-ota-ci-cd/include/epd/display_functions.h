#ifndef DISPLAY_FUNCTIONS_H
#define DISPLAY_FUNCTIONS_H 

void clear_display()
{
        setSourceVoltage(15000);
		
	uint8_t reg0fh_value = spi_read_command_1param(0x0f);

	spi_write_command_1param(0x0f, reg0fh_value|0x10); //
	UC8156_send_repeated_image_data(0xff); // 0xff is white
	spi_write_command_1param(0x0f, reg0fh_value&(~0x10)); //
	UC8156_send_repeated_image_data(0xff); // 0xff is white
	// if(single_display){
		UC8156_HVs_on();
		UC8156_update_display(FULL_UPDATE, NORMAL_4GL);
		UC8156_update_display(FULL_UPDATE, NORMAL_4GL);
		//UC8156_update_display(INIT_UPDATE);
		UC8156_HVs_off();
	// }else{
	// 	spi_write_command_1param_slave(0x0f, reg0fh_value|0x10); //
	// 	UC8156_send_repeated_image_data_slave(0xff); // 0xff is white
	// 	spi_write_command_1param_slave(0x0f, reg0fh_value&(~0x10)); //
	// 	UC8156_send_repeated_image_data_slave(0xff); // 0xff is white

	// 	spi_write_command_1param_slave(0x03, 0xc6); //Enable external HV supply for Slave

	// 	UC8156_HVs_on_dual();

	// 	UC8156_update_display_dual(FULL_UPDATE, NORMAL_4GL);
	// 	UC8156_update_display_dual(FULL_UPDATE, NORMAL_4GL);

	// 	UC8156_HVs_off_dual();
	// }
}

void black_display()
{
	uint8_t reg0fh_value = spi_read_command_1param(0x0f);

	spi_write_command_1param(0x0f, reg0fh_value|0x10); //
	UC8156_send_repeated_image_data(0x00); // 0xff is white
	spi_write_command_1param(0x0f, reg0fh_value&(~0x10)); //
	UC8156_send_repeated_image_data(0x00); // 0xff is white
	// if(single_display){
		UC8156_HVs_on();
		UC8156_update_display(FULL_UPDATE, NORMAL_4GL);
		UC8156_update_display(FULL_UPDATE, NORMAL_4GL);
		//UC8156_update_display(INIT_UPDATE);
		UC8156_HVs_off();
	// }else{
	// 	spi_write_command_1param_slave(0x0f, reg0fh_value|0x10); //
	// 	UC8156_send_repeated_image_data_slave(0xff); // 0xff is white
	// 	spi_write_command_1param_slave(0x0f, reg0fh_value&(~0x10)); //
	// 	UC8156_send_repeated_image_data_slave(0xff); // 0xff is white

	// 	spi_write_command_1param_slave(0x03, 0xc6); //Enable external HV supply for Slave

	// 	UC8156_HVs_on_dual();

	// 	UC8156_update_display_dual(FULL_UPDATE, NORMAL_4GL);
	// 	UC8156_update_display_dual(FULL_UPDATE, NORMAL_4GL);

	// 	UC8156_HVs_off_dual();
	// }
}

#endif /* DISPLAY_FUNCTIONS_H */