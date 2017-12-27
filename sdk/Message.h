#ifndef MESSAGE_H
#define MESSAGE_H
#include <QByteArray>
#include <QDataStream>

struct Message {

  /*! \enum class Type
   *
   * Defiend worker and job
   */
  enum class Type {
    WORKER_REGISTER,   // sent by worker when first connect
    WORKER_UNREGISTER, // sent by worker when disconnect
    ALL_JOBS_ABORT,    // sent by app each time cancel picture
    JOB_REQUEST,       // sent by app to calculate a specific line
    JOB_RESULT         // sent by worker with calculated result
  };

  Message(const Type type = Type::WORKER_REGISTER,
          const QByteArray &data = QByteArray())
      : type(type), data(data) {}

  ~Message() {}

  Type type;
  QByteArray data;
};

inline QDataStream &operator<<(QDataStream &out, const Message &message) {
  out << static_cast<qint8>(message.type) << message.data;
  return out;
}

inline QDataStream &operator>>(QDataStream &in, Message &message) {
  qint8 type;
  in >> type;
  in >> message.data;
  message.type = static_cast<Message::Type>(type);
  return in;
}
#endif
