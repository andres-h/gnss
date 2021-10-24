* template: $template
plugin $seedlink.source.id cmd="$seedlink.plugin_dir/gnss_plugin --udpport $sources.gnss.udpport --stations-from $sources.gnss.stationsFrom"
             timeout = 600
             start_retry = 60
             shutdown_wait = 10

