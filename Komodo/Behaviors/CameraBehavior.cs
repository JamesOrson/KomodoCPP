using Komodo.Core;
using Komodo.Core.Engine.Components;
using Komodo.Core.Engine.Input;
using Microsoft.Xna.Framework;

namespace Komodo.Behaviors
{
    public class CameraBehavior : BehaviorComponent
    {
        #region Constructors
        public CameraBehavior(CameraComponent camera, int playerIndex) : base()
        {
            if (!InputManager.IsValidPlayerIndex(playerIndex))
            {
                playerIndex = 0;
            }
            PlayerIndex = playerIndex;
            Camera = camera;
            PanVelocity = 50f;
        }
        #endregion Constructors

        #region Members

        #region Public Members
        public CameraComponent Camera { get; set; }
        public int PlayerIndex { get; set; }
        public float PanVelocity { get; set; }
        #endregion Public Members

        #region Protected Members
        #endregion Protected Members

        #region Private Members
        #endregion Private Members

        #endregion Members

        #region Member Methods

        #region Public Member Methods
        public override void Update(GameTime gameTime)
        {
            var cameraLeft = InputManager.GetInput("camera_left", PlayerIndex);
            var cameraRight = InputManager.GetInput("camera_right", PlayerIndex);
            var cameraUp = InputManager.GetInput("camera_up", PlayerIndex);
            var cameraDown = InputManager.GetInput("camera_down", PlayerIndex);

            var direction = KomodoVector2.Zero;
            if (cameraLeft.State == InputState.Down)
            {
                direction = KomodoVector2.Add(direction, KomodoVector2.Left);
            }
            if (cameraRight.State == InputState.Down)
            {
                direction = KomodoVector2.Add(direction, KomodoVector2.Right);
            }
            if (cameraUp.State == InputState.Down)
            {
                direction = KomodoVector2.Add(direction, KomodoVector2.Up);
            }
            if (cameraDown.State == InputState.Down)
            {
                direction = KomodoVector2.Add(direction, KomodoVector2.Down);
            }

            var cameraPan = KomodoVector3.Multiply(
                new KomodoVector3(direction.X, direction.Y),
                PanVelocity * (float)gameTime.ElapsedGameTime.TotalSeconds
            );
            Camera.Pan(cameraPan);
        }
        #endregion Public Member Methods

        #region Protected Member Methods
        #endregion Protected Member Methods

        #region Private Member Methods
        #endregion Private Member Methods

        #endregion Member Methods
    }
}