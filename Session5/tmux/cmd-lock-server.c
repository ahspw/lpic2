/* $OpenBSD$ */

/*
 * Copyright (c) 2008 Nicholas Marriott <nicholas.marriott@gmail.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <sys/types.h>

#include "tmux.h"

/*
 * Lock commands.
 */

static enum cmd_retval	cmd_lock_server_exec(struct cmd *, struct cmdq_item *);

const struct cmd_entry cmd_lock_server_entry = {
	.name = "lock-server",
	.alias = "lock",

	.args = { "", 0, 0, NULL },
	.usage = "",

	.flags = CMD_AFTERHOOK,
	.exec = cmd_lock_server_exec
};

const struct cmd_entry cmd_lock_session_entry = {
	.name = "lock-session",
	.alias = "locks",

	.args = { "t:", 0, 0, NULL },
	.usage = CMD_TARGET_SESSION_USAGE,

	.target = { 't', CMD_FIND_SESSION, 0 },

	.flags = CMD_AFTERHOOK,
	.exec = cmd_lock_server_exec
};

const struct cmd_entry cmd_lock_client_entry = {
	.name = "lock-client",
	.alias = "lockc",

	.args = { "t:", 0, 0, NULL },
	.usage = CMD_TARGET_CLIENT_USAGE,

	.flags = CMD_AFTERHOOK|CMD_CLIENT_TFLAG,
	.exec = cmd_lock_server_exec
};

static enum cmd_retval
cmd_lock_server_exec(struct cmd *self, struct cmdq_item *item)
{
	struct cmd_find_state	*target = cmdq_get_target(item);
	struct client		*tc = cmdq_get_target_client(item);

	if (cmd_get_entry(self) == &cmd_lock_server_entry)
		server_lock();
	else if (cmd_get_entry(self) == &cmd_lock_session_entry)
		server_lock_session(target->s);
	else
		server_lock_client(tc);
	recalculate_sizes();

	return (CMD_RETURN_NORMAL);
}
