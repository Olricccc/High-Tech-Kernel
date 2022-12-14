
/* diagfwd_dbg_raw_data: for internal diag debug */
extern unsigned diag7k_debug_mask;
extern unsigned diag9k_debug_mask;

void __diagfwd_dbg_raw_data(void *buf, const char *src, unsigned dbg_flag, unsigned mask)
{
	static char reason_str[128];
	int len;

	switch (dbg_flag) {
	case DIAG_DBG_READ:
		len = sprintf(reason_str, "Read Packet Data from %s", src);
		break;
	case DIAG_DBG_WRITE:
		len = sprintf(reason_str, "Write Packet Data to %s", src);
		break;
	case DIAG_DBG_DROP:
		len = sprintf(reason_str, "Drop Packet Data from %s", src);
		break;
	default:
		/* We dont care about other reason */
		return;
	}

	if (mask || dbg_flag == DIAG_DBG_DROP) {
		/* for debug reason */
		len = sprintf(reason_str + len, "(%s)", "first 16 bytes");

	} else if (driver->qxdmusb_drop && driver->logging_mode == USB_MODE) {
	/* receive unknown packets */
		len = sprintf(reason_str + len, "(%s)", "Unknown packet");
	} else {
		/* We dont care about other reason */
		return;
	}
	if (diag7k_debug_mask || diag9k_debug_mask)
		print_hex_dump(KERN_INFO, reason_str, DUMP_PREFIX_ADDRESS, 16, 1, buf, 16, 1);
	else
		print_hex_dump(KERN_DEBUG, reason_str, DUMP_PREFIX_ADDRESS, 16, 1, buf, 16, 1);
}

