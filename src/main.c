#include <assert.h>
#include <zmq.h>

int main (void) {
  void *ctx = zmq_ctx_new ();
  assert (ctx);
  /* Create ZMQ_STREAM socket */
  void *socket = zmq_socket (ctx, ZMQ_SUB);
  assert (socket);
  int rc = zmq_setsockopt (socket, ZMQ_SUBSCRIBE, "", 0);
  assert (rc == 0);
  rc = zmq_connect (socket, "tcp://tball-test-push2-2hzcn6uhlgskf05c.us-east-1.opsworks-cm.io:10000");
  assert (rc == 0);

  zmq_close (socket); zmq_ctx_destroy (ctx);
  return 0;
}