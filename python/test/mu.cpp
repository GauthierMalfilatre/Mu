#include <quiz.h>
#include "execution_environment.h"

QUIZ_CASE(python_mu_import) {
  TestExecutionEnvironment env = init_environnement();
  assert_command_execution_fails(env, "Scene()");
  assert_command_execution_succeeds(env, "from mu import *");
  assert_command_execution_succeeds(env, "Scene()");
  deinit_environment();

  env = init_environnement();
  assert_command_execution_succeeds(env, "import mu");
  assert_command_execution_succeeds(env, "mu.SceneManager()");
  assert_command_execution_succeeds(env, "mu.Keyboard()");
  assert_command_execution_succeeds(env, "mu.EventBus()");
  assert_command_execution_succeeds(env, "mu.Event('x')");
  deinit_environment();
}

QUIZ_CASE(python_mu_scene) {
  assert_script_execution_succeeds(
    "from mu import Scene\n"
    "s = Scene()\n"
    "print(s.is_dirty())\n"
    "s.mark_clean()\n"
    "print(s.is_dirty())\n"
    "s.mark_dirty()\n"
    "print(s.is_dirty())\n",
    "True\nFalse\nTrue\n");
  // Scene() takes no argument
  assert_script_execution_fails("from mu import Scene\nScene(1)");
}

QUIZ_CASE(python_mu_scenemanager) {
  assert_script_execution_succeeds(
    "from mu import Scene, SceneManager\n"
    "log = []\n"
    "class S(Scene):\n"
    "  n = 0\n"
    "  def on_start(self, ctx):\n"
    "    log.append('start%d:%s' % (self.n, ctx))\n"
    "  def on_dispose(self, ctx):\n"
    "    log.append('dispose%d:%s' % (self.n, ctx))\n"
    "def mk(n):\n"
    "  s = S()\n"
    "  s.n = n\n"
    "  return s\n"
    "m = SceneManager()\n"
    "print(m.current())\n"
    "a = m.push(mk(1), 'x')\n"
    "b = m.push(mk(2))\n"
    "print(m.current() is b)\n"
    "print(m.pop('y') is b)\n"
    "print(m.current() is a)\n"
    "c = m.change(mk(3), 'z')\n"
    "print(m.current() is c)\n"
    "print(log)\n",
    "None\nTrue\nTrue\nTrue\nTrue\n"
    "['start1:x', 'start2:None', 'dispose2:y', 'dispose1:z', 'start3:z']\n");
  // pop on an empty manager raises
  assert_script_execution_fails("from mu import SceneManager\nSceneManager().pop()");
}

QUIZ_CASE(python_mu_event) {
  assert_script_execution_succeeds(
    "from mu import Event\n"
    "e = Event('hit', x=1, y=2)\n"
    "print(e.type)\n"
    "print(e.data['x'], e.data['y'])\n",
    "hit\n1 2\n");
  assert_script_execution_fails("from mu import Event\nEvent()");
}

QUIZ_CASE(python_mu_eventbus) {
  assert_script_execution_succeeds(
    "from mu import EventBus\n"
    "bus = EventBus()\n"
    "got = []\n"
    "bus.subscribe(lambda e: got.append('low'), 'a', priority=5)\n"
    "bus.subscribe(lambda e: got.append('high'), 'a', 'b', priority=1)\n"
    "bus.subscribe(lambda e: got.append('other'), 'c')\n"
    "ev = bus.dispatch('a', v=7)\n"
    "print(ev.type, ev.data['v'])\n"
    "bus.dispatch('b')\n"
    "bus.dispatch('unknown')\n"
    "print(got)\n",
    "a 7\n['high', 'low', 'high']\n");
}

QUIZ_CASE(python_mu_keyboard) {
  assert_script_execution_succeeds(
    "from mu import Keyboard\n"
    "k = Keyboard()\n"
    "k.update()\n"
    "print(k.press(0), k.release(0))\n",
    "False False\n");
  assert_script_execution_fails("from mu import Keyboard\nKeyboard(1)");
}
