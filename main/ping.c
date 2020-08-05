#include <string.h>
#include "concord.h"

#define TOKEN ""

void
pong(concord_message *msg)
{

        if (!strcmp("ping", msg->content)) concord_reply("pong", msg);
}

void
app_main()
{
        concord_client *bot;

        bot = concord_new_client();
        concord_login(bot, TOKEN);
        bot->message_callback = pong;
        concord_free_client(bot);
}
