#include "asterisk/format_cache.h"      /* for ast_format_gsm_efr */
#include "asterisk/frame.h"             /* for ast_frame, etc */

static uint8_t ex_gsm_efr[] = {
	0xc9, 0x11, 0x71, 0x6b, 0xe6, 0x67, 0x9e, 0x1e,
	0x00, 0x1e, 0x7a, 0xff, 0x00, 0x00, 0x00, 0x08,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
};

static struct ast_frame *gsm_efr_sample(void)
{
	static struct ast_frame f = {
		.frametype = AST_FRAME_VOICE,
		.datalen = sizeof(ex_gsm_efr),
		.samples = 160,
		.mallocd = 0,
		.offset = 0,
		.src = __PRETTY_FUNCTION__,
		.data.ptr = ex_gsm_efr,
	};

	f.subclass.format = ast_format_gsm_efr;

	return &f;
}
