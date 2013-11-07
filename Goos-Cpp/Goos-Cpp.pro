TEMPLATE = subdirs

SUBDIRS += \
    test \
    auctionsniper \
    auctionsniper-ui

test.depends = auctionsniper-ui
auctionsniper.depends = auctionsniper-ui
