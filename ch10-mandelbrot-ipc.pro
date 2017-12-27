TEMPLATE = subdirs
OTHER_FILES+= \
                            sdk/Message.h \
                            sdk/JobRequest.h \
                            sdk/JobResult.h \
                            sdk/MessageUtils.h \
                            mandelbrot-common.pri

SUBDIRS += \
    mandelbrot-worker \
    mandelbrot-app
