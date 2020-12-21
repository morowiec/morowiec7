#!/bin/bash

# Setup variables
backup_file=$(date +'%Y%m%d_%H%M')
echo "Backup file: ${backup_file}"
latest_dump=$(find ../ci/backups/ -name "morozab*" | sort -n | tail -1)
echo "Latest DB dump ${latest_dump}"

# Run drush commands
drush sql-dump --result-file=../ci/backups/${backup_file}.sql
drush sql-drop -y
drush sqlc < ${latest_dump}
drush upwd morowiec --password="pass"
drush cd sites/all/modules/contrib/registry_rebuild/
drush php registry_rebuild.php
drush cd /app/web
drush variable-set smtp_reroute_address morowiec+jt2dev@gmail.com
drush variable-set file_public_path sites/default/files
drush variable-set file_private_path sites/default/files_private
drush variable-set file_temporary_path /var/www/html/web/tmp
drush updb -y
drush cc all
drush en devel_debug_log -y
drush cc all