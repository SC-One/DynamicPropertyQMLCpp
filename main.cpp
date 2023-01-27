#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlPropertyMap>

class DynamicCpp : public QQmlPropertyMap {};

int main(int argc, char *argv[]) {
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  QGuiApplication app(argc, argv);

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(
      &engine, &QQmlApplicationEngine::objectCreated, &app,
      [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
      },
      Qt::QueuedConnection);
  qmlRegisterType<DynamicCpp>("github.com.sc_one", 1, 0, "DynamicCpp");
  engine.load(url);

  return app.exec();
}
