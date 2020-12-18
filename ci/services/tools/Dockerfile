FROM drupaldocker/php:5.6-cli

RUN pecl install xdebug-2.5.5 \
 && docker-php-ext-enable xdebug

COPY drupal-*.ini /usr/local/etc/php/conf.d/

# Install composer
RUN php -r "copy('https://getcomposer.org/installer', 'composer-setup.php');" \
    && php composer-setup.php \
    && mv composer.phar /usr/local/bin/composer \
    && php -r "unlink('composer-setup.php');"

# Install GD
RUN set -ex; \
	\
	apt-get update; \
	apt-get install -y --no-install-recommends \
		libjpeg-dev \
		libpng-dev \
		libpq-dev \
	; \
	\
	docker-php-ext-configure gd --with-png-dir=/usr --with-jpeg-dir=/usr; \
	docker-php-ext-install -j "$(nproc)" \
        gd \
        opcache \
        pdo_mysql \
        zip

RUN docker-php-ext-enable gd

RUN apt-get update && apt-get install -y mysql-client openssh-client rsync unzip \
  && composer global require drush/drush:8.* \
  && rm -f /usr/local/bin/drush \
  && ln -s ~/.composer/vendor/bin/drush /usr/local/bin/drush \
  && drush core-status -y \
  && rm -rf /var/lib/apt/lists/*

# Clean after install
RUN apt-get autoremove -y \
    && apt-get autoclean -y \
    && rm -rf /var/lib/apt/lists/*